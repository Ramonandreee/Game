// MOGUL (Project ATLAS) — Agent Subsystem implementation.
#include "Agents/MogulAgentSubsystem.h"
#include "MogulLog.h"

namespace
{
	const TCHAR* FirstNames[] = { TEXT("Alex"), TEXT("Sam"), TEXT("Noa"), TEXT("Liv"), TEXT("Vic"),
		TEXT("Dani"), TEXT("Theo"), TEXT("Mara"), TEXT("Iris"), TEXT("Leo"), TEXT("Nina"), TEXT("Caio"),
		TEXT("Bia"), TEXT("Sofia"), TEXT("Marco"), TEXT("Eva"), TEXT("Priya"), TEXT("Enzo"), TEXT("Mila") };
	const TCHAR* LastNames[] = { TEXT("Moreau"), TEXT("Sterling"), TEXT("Okafor"), TEXT("Vance"),
		TEXT("Reyes"), TEXT("Cho"), TEXT("Bianchi"), TEXT("Haddad"), TEXT("Costa"), TEXT("Nakamura"),
		TEXT("Adeyemi"), TEXT("Volkov"), TEXT("Mensah"), TEXT("Khan"), TEXT("Romano"), TEXT("Silva") };
	const TCHAR* Roles[] = { TEXT("Engenheiro(a)"), TEXT("Cientista de Dados"), TEXT("Designer"),
		TEXT("Head de Vendas"), TEXT("Operações"), TEXT("Gerente Geral"), TEXT("Marketing"), TEXT("Financeiro(a)") };
	const TCHAR* Families[] = { TEXT("tech"), TEXT("real"), TEXT("soft") };
	const TCHAR* TraitPool[] = { TEXT("Visionário"), TEXT("Workaholic"), TEXT("Calculista"),
		TEXT("Carismático"), TEXT("Leal"), TEXT("Ambicioso"), TEXT("Cético"), TEXT("Oportunista") };
}

void UMogulAgentSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogMogul, Log, TEXT("AgentSubsystem ready."));
}

FString UMogulAgentSubsystem::RandomName() const
{
	const FString F = FirstNames[FMath::RandRange(0, UE_ARRAY_COUNT(FirstNames) - 1)];
	const FString L = LastNames[FMath::RandRange(0, UE_ARRAY_COUNT(LastNames) - 1)];
	return F + TEXT(" ") + L;
}

FGuid UMogulAgentSubsystem::GenerateAgent(EMogulAgentKind Kind, int32 WealthTier)
{
	FMogulAgent A;
	A.Id = FGuid::NewGuid();
	A.Name = RandomName();
	A.Age = FMath::RandRange(26, 58);
	A.Role = Roles[FMath::RandRange(0, UE_ARRAY_COUNT(Roles) - 1)];
	A.Family = FName(Families[FMath::RandRange(0, UE_ARRAY_COUNT(Families) - 1)]);
	A.Kind = Kind;
	A.Tier = EMogulAgentTier::Social;
	A.Competence = FMath::RandRange(50, 92);
	A.Ambition = FMath::RandRange(35, 90);
	A.Integrity = FMath::RandRange(30, 95);

	const float WealthScales[] = { 40000.f, 400000.f, 8000000.f };
	const float Cap = WealthScales[FMath::Clamp(WealthTier, 0, 2)];
	A.Wealth = FMath::FRandRange(Cap * 0.1f, Cap);

	A.Personality.Openness = FMath::FRand();
	A.Personality.Conscientiousness = FMath::FRand();
	A.Personality.Extraversion = FMath::FRand();
	A.Personality.Agreeableness = FMath::FRand();
	A.Personality.Neuroticism = FMath::FRand();

	A.Traits.Add(TraitPool[FMath::RandRange(0, UE_ARRAY_COUNT(TraitPool) - 1)]);
	A.Traits.Add(TraitPool[FMath::RandRange(0, UE_ARRAY_COUNT(TraitPool) - 1)]);
	A.Relationship = FMath::RandRange(8, 20);

	Agents.Add(A.Id, A);
	return A.Id;
}

bool UMogulAgentSubsystem::GetAgent(FGuid Id, FMogulAgent& OutAgent) const
{
	if (const FMogulAgent* Found = Agents.Find(Id))
	{
		OutAgent = *Found;
		return true;
	}
	return false;
}

void UMogulAgentSubsystem::AddRelationship(FGuid Id, float Delta)
{
	if (FMogulAgent* A = Agents.Find(Id))
	{
		A->Relationship = FMath::Clamp(A->Relationship + Delta, 0.f, 100.f);
	}
}

void UMogulAgentSubsystem::Remember(FGuid Id, const FString& Summary, float Weight, int32 Day)
{
	if (FMogulAgent* A = Agents.Find(Id))
	{
		FMogulMemory M; M.Summary = Summary; M.Weight = Weight; M.Day = Day;
		A->Memory.Insert(M, 0);
		// Keep salient-first; compact the tail (docs/07 §3.3: saliency + decay).
		A->Memory.Sort([](const FMogulMemory& X, const FMogulMemory& Y){ return X.Weight > Y.Weight; });
		if (A->Memory.Num() > MaxMemories)
		{
			A->Memory.SetNum(MaxMemories);
		}
	}
}

void UMogulAgentSubsystem::SetTier(FGuid Id, EMogulAgentTier Tier)
{
	if (FMogulAgent* A = Agents.Find(Id))
	{
		A->Tier = Tier;
	}
}
