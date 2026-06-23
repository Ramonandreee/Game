// MOGUL (Project ATLAS) — Simulation Core implementation.
#include "Core/MogulSimulationSubsystem.h"
#include "Core/MogulEventBus.h"
#include "Economy/MogulEconomySubsystem.h"
#include "MogulLog.h"

void UMogulSimulationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	// Ensure dependencies are created before us.
	Collection.InitializeDependency(UMogulEconomySubsystem::StaticClass());
	Collection.InitializeDependency(UMogulEventBus::StaticClass());
	UE_LOG(LogMogul, Log, TEXT("SimulationSubsystem online (world tick)."));
}

void UMogulSimulationSubsystem::Tick(float DeltaTime)
{
	if (!bAutoAdvance) { return; }
	Accumulator += DeltaTime;
	if (Accumulator >= SecondsPerDay)
	{
		Accumulator -= SecondsPerDay;
		AdvanceDay();
	}
}

void UMogulSimulationSubsystem::AdvanceDay()
{
	UGameInstance* GI = GetGameInstance();
	if (!GI) { return; }

	if (UMogulEconomySubsystem* Econ = GI->GetSubsystem<UMogulEconomySubsystem>())
	{
		Econ->TickEconomyDay();

		// Fan out the day on the event bus so any system (agents, media, UI) can react.
		if (UMogulEventBus* Bus = GI->GetSubsystem<UMogulEventBus>())
		{
			Bus->Emit(TEXT("DayAdvanced"), FString::Printf(TEXT("day=%d;net=%.0f"), Econ->Day, Econ->GetNetWorth()));
		}
	}
}

TStatId UMogulSimulationSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UMogulSimulationSubsystem, STATGROUP_Tickables);
}

ETickableTickType UMogulSimulationSubsystem::GetTickableTickType() const
{
	// Never tick the CDO.
	return IsTemplate() ? ETickableTickType::Never : ETickableTickType::Conditional;
}

bool UMogulSimulationSubsystem::IsTickable() const
{
	return bAutoAdvance && !IsTemplate();
}
