// MOGUL (Project ATLAS) — Agent Subsystem.
// Registry + generation + memory for Tier 2/3 agents (docs/07). Tier 0/1 crowds
// are Mass entities (see MassEntity plugin) and are NOT registered here.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Agents/MogulAgentTypes.h"
#include "MogulAgentSubsystem.generated.h"

UCLASS()
class MOGUL_API UMogulAgentSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// Generate a persistent agent. Tier defaults to Social; "hydrates" to Protagonist
	// on close interaction and back down afterwards (LOD of cognition, docs/07 §2).
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Agents")
	FGuid GenerateAgent(EMogulAgentKind Kind, int32 WealthTier = 0);

	UFUNCTION(BlueprintCallable, Category = "MOGUL|Agents")
	bool GetAgent(FGuid Id, FMogulAgent& OutAgent) const;

	UFUNCTION(BlueprintCallable, Category = "MOGUL|Agents")
	void AddRelationship(FGuid Id, float Delta);

	// Episodic memory write with saliency weight; list is capped & kept salient-first.
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Agents")
	void Remember(FGuid Id, const FString& Summary, float Weight, int32 Day);

	UFUNCTION(BlueprintCallable, Category = "MOGUL|Agents")
	void SetTier(FGuid Id, EMogulAgentTier Tier);

	int32 NumAgents() const { return Agents.Num(); }

private:
	UPROPERTY() TMap<FGuid, FMogulAgent> Agents;

	static constexpr int32 MaxMemories = 6;
	FString RandomName() const;
};
