// MOGUL (Project ATLAS) — Simulation Core (the "world tick", docs/10 §3).
// Drives the world independently of rendering. Advances days, fans out via the
// Event Bus. Production adds LOD-of-simulation rings (Focus/Near/Far/Dormant).
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tickable.h"
#include "MogulSimulationSubsystem.generated.h"

UCLASS()
class MOGUL_API UMogulSimulationSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// FTickableGameObject
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;
	virtual ETickableTickType GetTickableTickType() const override;
	virtual bool IsTickable() const override;

	// Advance one simulation day: economy tick + agent behaviour + events.
	// Called explicitly on "sleep" (player-driven), or automatically if bAutoAdvance.
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Sim")
	void AdvanceDay();

	// If true, the offscreen world advances on a real-time cadence (docs/10 §3.1).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOGUL|Sim")
	bool bAutoAdvance = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MOGUL|Sim")
	float SecondsPerDay = 120.f;

private:
	float Accumulator = 0.f;
};
