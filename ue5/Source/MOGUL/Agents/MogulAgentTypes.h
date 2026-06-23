// MOGUL (Project ATLAS) — agent data types (docs/07-NPC-AI-ARCHITECTURE.md).
#pragma once

#include "CoreMinimal.h"
#include "MogulAgentTypes.generated.h"

// LOD of cognition (docs/07 §2): cheap ambient crowds -> deep persistent agents.
UENUM(BlueprintType)
enum class EMogulAgentTier : uint8
{
	Ambient		UMETA(DisplayName = "Tier 0 — Ambiental (Mass)"),
	Functional	UMETA(DisplayName = "Tier 1 — Funcional"),
	Social		UMETA(DisplayName = "Tier 2 — Social persistente"),
	Protagonist	UMETA(DisplayName = "Tier 3 — Protagonista (diálogo)")
};

UENUM(BlueprintType)
enum class EMogulAgentKind : uint8
{
	Investor	UMETA(DisplayName = "Investidor"),
	Talent		UMETA(DisplayName = "Talento"),
	Client		UMETA(DisplayName = "Cliente"),
	Rival		UMETA(DisplayName = "Rival")
};

// OCEAN / Big Five (0..1).
USTRUCT(BlueprintType)
struct FMogulBigFive
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Openness = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Conscientiousness = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Extraversion = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Agreeableness = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Neuroticism = 0.5f;
};

// A remembered episode (docs/07 §3.3). Saliency-weighted; compacted over time.
USTRUCT(BlueprintType)
struct FMogulMemory
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString Summary;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Weight = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Day = 0;
};

USTRUCT(BlueprintType)
struct FMogulAgent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FGuid Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Age = 35;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString Role;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName Family;        // tech / real / soft
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EMogulAgentKind Kind = EMogulAgentKind::Talent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) EMogulAgentTier Tier = EMogulAgentTier::Social;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Competence = 60.f;  // 0..100
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Ambition = 60.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Integrity = 60.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) double Wealth = 50000.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FMogulBigFive Personality;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) float Relationship = 12.f; // with the player, 0..100
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FString> Traits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FMogulMemory> Memory; // most-salient first, capped
};
