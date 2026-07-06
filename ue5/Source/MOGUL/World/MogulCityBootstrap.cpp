// MOGUL (Project ATLAS) — Meridian world rig + greybox city implementation.
#include "World/MogulCityBootstrap.h"
#include "MogulLog.h"
#include "Components/DirectionalLightComponent.h"
#include "Components/SkyLightComponent.h"
#include "Components/SkyAtmosphereComponent.h"
#include "Components/VolumetricCloudComponent.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Components/PostProcessComponent.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/StaticMesh.h"
#include "Engine/Scene.h"
#include "Math/RandomStream.h"

AMogulCityBootstrap::AMogulCityBootstrap()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	// --- Sun: golden hour default (docs/13 §4.2). Auto exposure normalises the scene. ---
	Sun = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("Sun"));
	Sun->SetupAttachment(Root);
	Sun->SetRelativeRotation(FRotator(-12.f, 38.f, 0.f)); // low sun -> long shadows
	Sun->Intensity = 50000.f;                             // lux, physically plausible late sun
	Sun->LightSourceAngle = 0.6f;                         // soft disk -> soft shadow penumbra
	Sun->SetAtmosphereSunLight(true);

	Atmosphere = CreateDefaultSubobject<USkyAtmosphereComponent>(TEXT("Atmosphere"));
	Atmosphere->SetupAttachment(Root);

	Clouds = CreateDefaultSubobject<UVolumetricCloudComponent>(TEXT("Clouds"));
	Clouds->SetupAttachment(Root);

	SkyLight = CreateDefaultSubobject<USkyLightComponent>(TEXT("SkyLight"));
	SkyLight->SetupAttachment(Root);
	SkyLight->SetRealTimeCaptureEnabled(true); // sky GI tracks the sun/atmosphere live

	Fog = CreateDefaultSubobject<UExponentialHeightFogComponent>(TEXT("Fog"));
	Fog->SetupAttachment(Root);
	Fog->SetVolumetricFog(true);
	Fog->SetFogDensity(0.02f);

	// --- Restrained cinematic post. Bloom/exposure ported from the prototype tuning. ---
	PostProcess = CreateDefaultSubobject<UPostProcessComponent>(TEXT("PostProcess"));
	PostProcess->SetupAttachment(Root);
	PostProcess->bUnbound = true;
	FPostProcessSettings& S = PostProcess->Settings;
	S.bOverride_AutoExposureMethod = true; S.AutoExposureMethod = EAutoExposureMethod::AEM_Histogram;
	S.bOverride_AutoExposureBias   = true; S.AutoExposureBias   = 0.3f;
	S.bOverride_BloomIntensity     = true; S.BloomIntensity     = 0.2f;  // user-calibrated
	S.bOverride_MotionBlurAmount   = true; S.MotionBlurAmount   = 0.35f;
	S.bOverride_VignetteIntensity  = true; S.VignetteIntensity  = 0.4f;
	S.bOverride_FilmGrainIntensity = true; S.FilmGrainIntensity = 0.04f;
}

void AMogulCityBootstrap::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (bGenerateCity)
	{
		BuildGreyboxCity();
	}
}

void AMogulCityBootstrap::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogMogul, Log, TEXT("Meridian rig online: sun/sky/fog/clouds + post + greybox (%d city meshes)."), CityMeshes.Num());
}

FName AMogulCityBootstrap::DistrictAtMeters(float X, float Y)
{
	// Same tests as the prototype's districtAt(x, z); UE Y maps to prototype z.
	if (X < -70.f && Y >  20.f) return TEXT("Boroughs");
	if (X < -20.f && Y <= 20.f) return TEXT("Grid");
	if (X >=  60.f && Y < -20.f) return TEXT("Sterling");
	if (X >=  60.f && Y >= 60.f) return TEXT("Ironside");
	if (X >= -20.f && X < 60.f && Y > 40.f) return TEXT("Goldhaven");
	return TEXT("Midtown");
}

UInstancedStaticMeshComponent* AMogulCityBootstrap::MakeCityISM(UStaticMesh* Mesh, UMaterialInterface* BaseMat, const FLinearColor& Tint)
{
	UInstancedStaticMeshComponent* ISM = NewObject<UInstancedStaticMeshComponent>(this);
	// UCS creation method => the engine cleans these up on every reconstruction,
	// so editing RandomSeed in the editor regenerates the city with no leaks.
	ISM->CreationMethod = EComponentCreationMethod::UserConstructionScript;
	ISM->SetupAttachment(Root);
	ISM->SetMobility(EComponentMobility::Static);
	ISM->SetStaticMesh(Mesh);
	if (BaseMat)
	{
		UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(BaseMat, this);
		MID->SetVectorParameterValue(TEXT("Color"), Tint);
		ISM->SetMaterial(0, MID);
	}
	ISM->RegisterComponent();
	CityMeshes.Add(ISM);
	return ISM;
}

void AMogulCityBootstrap::BuildGreyboxCity()
{
	CityMeshes.Reset(); // previous UCS components are disposed by the engine

	UStaticMesh* Cube = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube.Cube"));
	UMaterialInterface* BaseMat = LoadObject<UMaterialInterface>(nullptr, TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial"));
	if (!Cube)
	{
		UE_LOG(LogMogul, Warning, TEXT("Greybox: engine cube mesh unavailable; city generation skipped."));
		return;
	}

	const float M = 100.f;           // meters -> unreal cm
	const float Bound = BoundMeters; // prototype-compatible coordinates (meters)
	FRandomStream Rand(RandomSeed);

	// Ground slab: top face at Z=0.
	UInstancedStaticMeshComponent* Ground = MakeCityISM(Cube, BaseMat, FLinearColor(0.030f, 0.033f, 0.038f));
	Ground->AddInstance(FTransform(FRotator::ZeroRotator, FVector(0.f, 0.f, -0.5f * M), FVector(2.f * Bound + 200.f, 2.f * Bound + 200.f, 1.f)));

	// Road grid: dark strips, top ~2cm above ground (mirrors the prototype layout).
	UInstancedStaticMeshComponent* Roads = MakeCityISM(Cube, BaseMat, FLinearColor(0.012f, 0.013f, 0.015f));
	for (float i = -Bound; i <= Bound; i += 40.f)
	{
		Roads->AddInstance(FTransform(FRotator::ZeroRotator, FVector(i * M, 0.f, 0.f), FVector(12.f, 2.f * Bound, 0.04f)));
		Roads->AddInstance(FTransform(FRotator::ZeroRotator, FVector(0.f, i * M, 0.f), FVector(2.f * Bound, 12.f, 0.04f)));
	}

	// District identity (docs/13 §4.6): tint + height range per region.
	struct FStyle { FLinearColor Tint; FVector2D HeightRange; };
	TMap<FName, FStyle> Styles;
	Styles.Add(TEXT("Sterling"),  { FLinearColor(0.060f, 0.100f, 0.160f), FVector2D(60.0, 150.0) }); // glass towers
	Styles.Add(TEXT("Grid"),      { FLinearColor(0.050f, 0.070f, 0.100f), FVector2D(20.0,  60.0) }); // modern corporate
	Styles.Add(TEXT("Boroughs"),  { FLinearColor(0.100f, 0.070f, 0.050f), FVector2D(10.0,  26.0) }); // warm brick
	Styles.Add(TEXT("Ironside"),  { FLinearColor(0.035f, 0.040f, 0.045f), FVector2D( 8.0,  20.0) }); // industrial
	Styles.Add(TEXT("Goldhaven"), { FLinearColor(0.140f, 0.110f, 0.060f), FVector2D(24.0,  70.0) }); // light stone
	Styles.Add(TEXT("Midtown"),   { FLinearColor(0.060f, 0.065f, 0.075f), FVector2D(14.0,  42.0) });

	TMap<FName, UInstancedStaticMeshComponent*> ISMs;
	for (const TPair<FName, FStyle>& P : Styles)
	{
		ISMs.Add(P.Key, MakeCityISM(Cube, BaseMat, P.Value.Tint));
	}

	int32 Buildings = 0;
	for (float x = -Bound + 20.f; x < Bound; x += 40.f)
	{
		for (float y = -Bound + 20.f; y < Bound; y += 40.f)
		{
			const float BX = x + Rand.FRandRange(-6.f, 6.f);
			const float BY = y + Rand.FRandRange(-6.f, 6.f);
			const FName D = DistrictAtMeters(BX, BY);
			const FStyle& St = Styles[D];
			const float H = Rand.FRandRange((float)St.HeightRange.X, (float)St.HeightRange.Y);
			const float W = Rand.FRandRange(14.f, 24.f);
			const float Dp = Rand.FRandRange(14.f, 24.f);
			ISMs[D]->AddInstance(FTransform(FRotator::ZeroRotator, FVector(BX * M, BY * M, H * 0.5f * M), FVector(W, Dp, H)));
			Buildings++;
			// Financial-district towers get a podium base (classic skyline massing).
			if (D == TEXT("Sterling") && H > 80.f && Rand.FRand() < 0.7f)
			{
				const float PH = Rand.FRandRange(8.f, 14.f);
				ISMs[D]->AddInstance(FTransform(FRotator::ZeroRotator, FVector(BX * M, BY * M, PH * 0.5f * M),
					FVector(W + Rand.FRandRange(6.f, 10.f), Dp + Rand.FRandRange(6.f, 10.f), PH)));
			}
		}
	}
	UE_LOG(LogMogul, Log, TEXT("Greybox Meridian built: %d buildings across %d district meshes (seed %d)."), Buildings, ISMs.Num(), RandomSeed);
}
