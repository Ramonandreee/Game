// MOGUL (Project ATLAS) — versioned save object (docs/10 §7).
// Versioned so saves survive patches/DLC for years (schema migration on load).
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Economy/MogulEconomyTypes.h"
#include "Agents/MogulAgentTypes.h"
#include "MogulSaveGame.generated.h"

UCLASS()
class MOGUL_API UMogulSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	// Bump when the schema changes; migrate older saves in the Save subsystem.
	static constexpr int32 CurrentVersion = 1;

	UPROPERTY() int32 SaveVersion = CurrentVersion;
	UPROPERTY() FDateTime SavedAtUtc;

	// --- economy snapshot ---
	UPROPERTY() int32 Day = 1;
	UPROPERTY() int32 PhaseLevel = 1;
	UPROPERTY() double Cash = 1400.0;
	UPROPERTY() FMogulMarket Market;
	UPROPERTY() TArray<FMogulCompany> Companies;

	// --- player snapshot ---
	UPROPERTY() float SkillNegotiation = 10.f;
	UPROPERTY() float SkillCharisma = 12.f;
	UPROPERTY() float SkillFinance = 8.f;
	UPROPERTY() float SkillLeadership = 8.f;
	UPROPERTY() float RepMarket = 5.f;
	UPROPERTY() float RepTalent = 5.f;
	UPROPERTY() float RepPublic = 6.f;

	// --- agents snapshot (Tier 2/3 persistent minds) ---
	UPROPERTY() TArray<FMogulAgent> Agents;
};
