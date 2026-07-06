// MOGUL (Project ATLAS) — Meridian world rig + greybox city (docs/13).
// One actor that turns ANY level into the photoreal starting point:
// physically-based sky/sun/fog/clouds + restrained AAA post-process + the
// same district massing as the browser prototype (deterministic by seed,
// docs/10 §7). Drop it in a level, or let AMogulGameModeBase spawn it.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MogulCityBootstrap.generated.h"

class USceneComponent;
class UDirectionalLightComponent;
class USkyLightComponent;
class USkyAtmosphereComponent;
class UVolumetricCloudComponent;
class UExponentialHeightFogComponent;
class UPostProcessComponent;
class UInstancedStaticMeshComponent;
class UStaticMesh;
class UMaterialInterface;

UCLASS()
class MOGUL_API AMogulCityBootstrap : public AActor
{
	GENERATED_BODY()

public:
	AMogulCityBootstrap();

	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;

	// Deterministic massing — same doctrine as the save system (regenerate by seed).
	UPROPERTY(EditAnywhere, Category = "Meridian")
	int32 RandomSeed = 7;

	UPROPERTY(EditAnywhere, Category = "Meridian")
	bool bGenerateCity = true;

	// City half-extent in meters (mirrors the prototype's BOUND = 300).
	UPROPERTY(EditAnywhere, Category = "Meridian")
	float BoundMeters = 300.f;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Meridian") TObjectPtr<USceneComponent> Root;
	UPROPERTY(VisibleAnywhere, Category = "Meridian|Lighting") TObjectPtr<UDirectionalLightComponent> Sun;
	UPROPERTY(VisibleAnywhere, Category = "Meridian|Lighting") TObjectPtr<USkyAtmosphereComponent> Atmosphere;
	UPROPERTY(VisibleAnywhere, Category = "Meridian|Lighting") TObjectPtr<USkyLightComponent> SkyLight;
	UPROPERTY(VisibleAnywhere, Category = "Meridian|Lighting") TObjectPtr<UVolumetricCloudComponent> Clouds;
	UPROPERTY(VisibleAnywhere, Category = "Meridian|Lighting") TObjectPtr<UExponentialHeightFogComponent> Fog;
	UPROPERTY(VisibleAnywhere, Category = "Meridian|Lighting") TObjectPtr<UPostProcessComponent> PostProcess;

	UPROPERTY(Transient) TArray<TObjectPtr<UInstancedStaticMeshComponent>> CityMeshes;

private:
	void BuildGreyboxCity();
	UInstancedStaticMeshComponent* MakeCityISM(UStaticMesh* Mesh, UMaterialInterface* BaseMat, const FLinearColor& Tint);
	static FName DistrictAtMeters(float X, float Y);
};
