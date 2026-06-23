// MOGUL (Project ATLAS) — Game Instance.
#include "Core/MogulGameInstance.h"
#include "MogulLog.h"

void UMogulGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogMogul, Log, TEXT("MOGUL GameInstance initialised. Global subsystems online (Economy/Agents/Simulation/Save)."));
	// GameInstanceSubsystems auto-initialise here. The SimulationSubsystem (FTickableGameObject)
	// drives the world tick from this point — see Core/MogulSimulationSubsystem.
}

void UMogulGameInstance::Shutdown()
{
	UE_LOG(LogMogul, Log, TEXT("MOGUL GameInstance shutting down."));
	Super::Shutdown();
}
