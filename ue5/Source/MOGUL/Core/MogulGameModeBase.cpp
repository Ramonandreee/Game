// MOGUL (Project ATLAS) — base Game Mode.
#include "Core/MogulGameModeBase.h"
#include "World/MogulCityBootstrap.h"
#include "Components/SkyAtmosphereComponent.h"
#include "EngineUtils.h"
#include "UObject/UObjectIterator.h"
#include "MogulLog.h"

AMogulGameModeBase::AMogulGameModeBase()
{
	// Player pawn / controller classes are set in the editor (or a BP child).
	// Until then the engine's DefaultPawn (fly + mouse look) inspects the world.
	PrimaryActorTick.bCanEverTick = false;
}

void AMogulGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	// Already rigged (placed by hand or by a previous spawn)? Done.
	if (TActorIterator<AMogulCityBootstrap>(World))
	{
		return;
	}

	// A level that ships its own sky (e.g. an engine template map) keeps it —
	// spawning a second sun/atmosphere there would double-light the scene.
	for (TObjectIterator<USkyAtmosphereComponent> It; It; ++It)
	{
		if (It->GetWorld() == World)
		{
			UE_LOG(LogMogul, Log, TEXT("Level has its own sky; Meridian rig not auto-spawned (place AMogulCityBootstrap manually to force)."));
			return;
		}
	}

	World->SpawnActor<AMogulCityBootstrap>(FVector::ZeroVector, FRotator::ZeroRotator);
	UE_LOG(LogMogul, Log, TEXT("Meridian rig auto-spawned into a sky-less level."));
}
