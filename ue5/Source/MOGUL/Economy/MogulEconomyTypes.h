// MOGUL (Project ATLAS) — economy data types.
// Mirrors the validated prototype model (game/index.html, world/index.html).
#pragma once

#include "CoreMinimal.h"
#include "MogulEconomyTypes.generated.h"

UENUM(BlueprintType)
enum class EMogulCycle : uint8
{
	Recession	UMETA(DisplayName = "Recessão"),
	Stable		UMETA(DisplayName = "Estável"),
	Boom		UMETA(DisplayName = "Aquecido")
};

UENUM(BlueprintType)
enum class EMogulNicheFamily : uint8
{
	Tech	UMETA(DisplayName = "Tech"),
	Real	UMETA(DisplayName = "Real Economy"),
	Soft	UMETA(DisplayName = "Soft / Marca")
};

UENUM(BlueprintType)
enum class EMogulPhase : uint8
{
	Survival	UMETA(DisplayName = "Sobrevivência"),
	Growth		UMETA(DisplayName = "Crescimento"),
	Scale		UMETA(DisplayName = "Escala"),
	Influence	UMETA(DisplayName = "Influência"),
	Legacy		UMETA(DisplayName = "Legado")
};

// Denormalised employee reference held by a company for fast economy math.
// The full agent profile (Big Five, memory) lives in the Agent subsystem.
USTRUCT(BlueprintType)
struct FMogulEmployeeRef
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FGuid AgentId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Competence = 60.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Salary = 120.f;   // per day
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float RoleFit = 1.f;    // 1.18 fit / 0.9 mismatch / 1.05 generalist
};

USTRUCT(BlueprintType)
struct FMogulCompany
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FGuid Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName NicheId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float BaseRevenue = 80.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Ops = 42.f;     // operational quality 0..100
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Scale = 1.f;    // demand multiplier (clients/virality/shocks)
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Overhead = 24.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 AgeDays = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool bAIOwned = false; // player vs. AI competitor
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FMogulEmployeeRef> Employees;
};

USTRUCT(BlueprintType)
struct FMogulMarket
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) EMogulCycle Cycle = EMogulCycle::Stable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Multiplier = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float InterestRate = 6.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Mood = 0.0f;     // -1..1
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Target = 1.0f;
};

// Runtime niche parameters (loaded from UMogulNicheDataAsset, or defaults).
USTRUCT(BlueprintType)
struct FMogulNicheParams
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName NicheId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EMogulNicheFamily Family = EMogulNicheFamily::Tech;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CostMin = 3000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float CostMax = 5000.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float BaseRevMin = 60.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float BaseRevMax = 110.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float RiskPerDay = 0.10f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float GrowthMultiple = 1.18f;
};
