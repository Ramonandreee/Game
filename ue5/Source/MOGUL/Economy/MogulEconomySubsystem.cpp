// MOGUL (Project ATLAS) — Economy Subsystem implementation.
// Formulas are a faithful port of the headless-validated prototype model.
#include "Economy/MogulEconomySubsystem.h"
#include "MogulLog.h"

void UMogulEconomySubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	SeedDefaultNiches();
	LoadNichesFromAssets();
	UE_LOG(LogMogul, Log, TEXT("EconomySubsystem ready: %d niches, cash %.0f."), Niches.Num(), Cash);
}

void UMogulEconomySubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UMogulEconomySubsystem::SeedDefaultNiches()
{
	auto Add = [this](FName Id, EMogulNicheFamily Fam, float CMin, float CMax, float BMin, float BMax, float Risk, float Growth)
	{
		FMogulNicheParams P; P.NicheId = Id; P.Family = Fam; P.CostMin = CMin; P.CostMax = CMax;
		P.BaseRevMin = BMin; P.BaseRevMax = BMax; P.RiskPerDay = Risk; P.GrowthMultiple = Growth;
		Niches.Add(Id, P);
	};
	// Same set & tuning as the validated browser prototype.
	Add("saas",    EMogulNicheFamily::Tech, 3000, 5000,  60, 110, 0.10f, 1.18f);
	Add("ai",      EMogulNicheFamily::Tech, 6000, 9000,  90, 160, 0.22f, 1.30f);
	Add("fintech", EMogulNicheFamily::Tech, 5000, 8000,  80, 140, 0.18f, 1.22f);
	Add("retail",  EMogulNicheFamily::Real, 2500, 4500,  55,  95, 0.12f, 1.10f);
	Add("logi",    EMogulNicheFamily::Real, 4000, 7000,  70, 120, 0.13f, 1.12f);
	Add("energy",  EMogulNicheFamily::Real, 9000, 15000, 130, 210, 0.14f, 1.16f);
	Add("media",   EMogulNicheFamily::Soft, 4000, 7000,  60, 150, 0.24f, 1.20f);
	Add("health",  EMogulNicheFamily::Soft, 6000, 10000, 100, 170, 0.12f, 1.14f);
}

void UMogulEconomySubsystem::LoadNichesFromAssets()
{
	// PRODUCTION: enumerate UMogulNicheDataAsset via UAssetManager and override/extend
	// the defaults so designers add sectors with zero code change (docs/06 §3, docs/10).
	// Left as a documented hook so the spine compiles without AssetManager config.
}

void UMogulEconomySubsystem::RegisterNiche(const FMogulNicheParams& Params)
{
	Niches.Add(Params.NicheId, Params);
}

bool UMogulEconomySubsystem::GetNicheParams(FName NicheId, FMogulNicheParams& OutParams) const
{
	if (const FMogulNicheParams* Found = Niches.Find(NicheId))
	{
		OutParams = *Found;
		return true;
	}
	OutParams = FMogulNicheParams();
	return false;
}

float UMogulEconomySubsystem::SkillAverage() const
{
	return (SkillNegotiation + SkillCharisma + SkillFinance + SkillLeadership) * 0.25f;
}

float UMogulEconomySubsystem::GetCompanyRevenue(const FMogulCompany& Co) const
{
	float Emp = 0.f;
	for (const FMogulEmployeeRef& E : Co.Employees)
	{
		Emp += E.Competence * 0.012f * E.RoleFit;
	}
	const float Rep = 1.f + (RepMarket - 5.f) * 0.012f + (RepPublic - 5.f) * 0.006f;
	const float Ops = 0.45f + Co.Ops / 100.f * 0.95f;
	const float Founder = 1.f + (SkillAverage() - 8.f) * 0.01f;
	const float Rev = Co.BaseRevenue * (1.f + Emp) * Ops * Market.Multiplier * Rep * Founder * Co.Scale;
	return FMath::Max(0.f, Rev);
}

float UMogulEconomySubsystem::GetCompanyCosts(const FMogulCompany& Co) const
{
	float Sal = 0.f;
	for (const FMogulEmployeeRef& E : Co.Employees) { Sal += E.Salary; }
	return Sal + Co.Overhead;
}

float UMogulEconomySubsystem::GetCompanyProfit(const FMogulCompany& Co) const
{
	return GetCompanyRevenue(Co) - GetCompanyCosts(Co);
}

float UMogulEconomySubsystem::GetCompanyValue(const FMogulCompany& Co) const
{
	FMogulNicheParams P; GetNicheParams(Co.NicheId, P);
	const float Annual = GetCompanyProfit(Co) * 365.f;
	const float Mult = (6.f + P.GrowthMultiple * 4.f) * (0.7f + Market.Multiplier * 0.4f);
	const float V = FMath::Max(GetCompanyRevenue(Co) * 36.f, Annual * Mult / 12.f);
	return FMath::Max(0.f, V);
}

double UMogulEconomySubsystem::GetNetWorth() const
{
	double N = Cash;
	for (const FMogulCompany& Co : Companies)
	{
		if (!Co.bAIOwned) { N += GetCompanyValue(Co); }
	}
	return N;
}

float UMogulEconomySubsystem::DailyExpenses() const
{
	return 40.f + 6.f + (float)(PhaseLevel * PhaseLevel) * 4.f; // rent + lifestyle creep
}

FGuid UMogulEconomySubsystem::FoundCompany(FName NicheId, const FString& Name, bool bAIOwned)
{
	FMogulNicheParams P;
	GetNicheParams(NicheId, P);
	const float Cost = FMath::FRandRange(P.CostMin, P.CostMax);
	const float Base = FMath::FRandRange(P.BaseRevMin, P.BaseRevMax) * (0.9f + SkillAverage() * 0.01f);

	FMogulCompany Co;
	Co.Id = FGuid::NewGuid();
	Co.Name = Name.IsEmpty() ? FString::Printf(TEXT("NewCo %s"), *NicheId.ToString()) : Name;
	Co.NicheId = NicheId;
	Co.BaseRevenue = Base;
	Co.Ops = 42.f;
	Co.Scale = 1.f;
	Co.Overhead = FMath::RoundToFloat(Base * 0.30f);
	Co.bAIOwned = bAIOwned;

	if (!bAIOwned) { Cash -= Cost; }
	Companies.Add(Co);
	UpdatePhase();
	UE_LOG(LogMogul, Log, TEXT("Founded '%s' (%s)%s. Cost %.0f."), *Co.Name, *NicheId.ToString(), bAIOwned ? TEXT(" [AI]") : TEXT(""), Cost);
	return Co.Id;
}

void UMogulEconomySubsystem::TickEconomyDay()
{
	double CoNet = 0.0;
	for (FMogulCompany& Co : Companies)
	{
		Co.AgeDays++;
		const float Profit = GetCompanyProfit(Co);
		if (!Co.bAIOwned) { CoNet += Profit; }
		Co.Ops = FMath::Clamp(Co.Ops - FMath::FRandRange(0.4f, 1.2f), 0.f, 100.f);
		Co.Scale *= FMath::FRandRange(0.998f, 1.004f);
		FMogulNicheParams P; GetNicheParams(Co.NicheId, P);
		if (FMath::FRand() < P.RiskPerDay * 0.05f)
		{
			Co.Scale *= FMath::FRandRange(0.82f, 0.93f);
		}
	}
	Cash += CoNet;
	Cash -= DailyExpenses();

	MarketTick();
	UpdatePhase();
	Day++;

	// Agent behaviour (raises/leaving/poaching) and world events are driven by the
	// Agent + Simulation subsystems, which listen to the world tick (EDA, docs/10 §3.2).
	OnDayTicked.Broadcast(Day);
}

void UMogulEconomySubsystem::MarketTick()
{
	Market.Mood = FMath::Clamp(Market.Mood + FMath::FRandRange(-0.1f, 0.1f), -1.f, 1.f);
	if (FMath::FRand() < 0.045f)
	{
		const float R = FMath::FRand();
		if (R < 0.33f)      { Market.Cycle = EMogulCycle::Recession; Market.Target = 0.78f; Market.InterestRate = FMath::Clamp(Market.InterestRate + FMath::FRandRange(0.5f, 2.f), 1.f, 18.f); }
		else if (R < 0.66f) { Market.Cycle = EMogulCycle::Boom;      Market.Target = 1.28f; Market.InterestRate = FMath::Clamp(Market.InterestRate - FMath::FRandRange(0.3f, 1.2f), 1.f, 18.f); }
		else                { Market.Cycle = EMogulCycle::Stable;    Market.Target = 1.0f; }
	}
	Market.Multiplier += (Market.Target - Market.Multiplier) * 0.15f + Market.Mood * 0.01f;
	Market.Multiplier = FMath::Clamp(Market.Multiplier, 0.6f, 1.5f);
}

void UMogulEconomySubsystem::UpdatePhase()
{
	const double Net = GetNetWorth();
	const bool bHasCompany = Companies.ContainsByPredicate([](const FMogulCompany& C){ return !C.bAIOwned; });
	int32 NewPhase = 1;
	if (Net >= 150000000.0)      NewPhase = 5;
	else if (Net >= 20000000.0)  NewPhase = 4;
	else if (Net >= 1200000.0)   NewPhase = 3;
	else if (Net >= 60000.0 && bHasCompany) NewPhase = 2;
	if (NewPhase > PhaseLevel)
	{
		PhaseLevel = NewPhase;
		UE_LOG(LogMogul, Log, TEXT("PHASE UP -> %d (net %.0f)"), PhaseLevel, Net);
	}
}
