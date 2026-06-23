// MOGUL (Project ATLAS) — Economy Subsystem (the "Economy Engine" of docs/10 §4).
// Carries the SAME validated model proven in the browser prototypes into engine C++.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Economy/MogulEconomyTypes.h"
#include "MogulEconomySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMogulOnDayTicked, int32, Day);

UCLASS()
class MOGUL_API UMogulEconomySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// ---- economy state (production splits player skills/rep into a PlayerState) ----
	UPROPERTY(BlueprintReadOnly, Category = "MOGUL|Economy") double Cash = 1400.0;
	UPROPERTY(BlueprintReadOnly, Category = "MOGUL|Economy") int32 Day = 1;
	UPROPERTY(BlueprintReadOnly, Category = "MOGUL|Economy") int32 PhaseLevel = 1;
	UPROPERTY(BlueprintReadOnly, Category = "MOGUL|Economy") FMogulMarket Market;
	UPROPERTY(BlueprintReadOnly, Category = "MOGUL|Economy") TArray<FMogulCompany> Companies;

	UPROPERTY(BlueprintReadWrite, Category = "MOGUL|Player") float SkillNegotiation = 10.f;
	UPROPERTY(BlueprintReadWrite, Category = "MOGUL|Player") float SkillCharisma = 12.f;
	UPROPERTY(BlueprintReadWrite, Category = "MOGUL|Player") float SkillFinance = 8.f;
	UPROPERTY(BlueprintReadWrite, Category = "MOGUL|Player") float SkillLeadership = 8.f;
	UPROPERTY(BlueprintReadWrite, Category = "MOGUL|Player") float RepMarket = 5.f;
	UPROPERTY(BlueprintReadWrite, Category = "MOGUL|Player") float RepTalent = 5.f;
	UPROPERTY(BlueprintReadWrite, Category = "MOGUL|Player") float RepPublic = 6.f;

	UPROPERTY(BlueprintAssignable, Category = "MOGUL|Economy") FMogulOnDayTicked OnDayTicked;

	// ---- queries (the validated formulas) ----
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") float SkillAverage() const;
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") float GetCompanyRevenue(const FMogulCompany& Co) const;
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") float GetCompanyCosts(const FMogulCompany& Co) const;
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") float GetCompanyProfit(const FMogulCompany& Co) const;
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") float GetCompanyValue(const FMogulCompany& Co) const;
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") double GetNetWorth() const;
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") float DailyExpenses() const;
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") bool GetNicheParams(FName NicheId, FMogulNicheParams& OutParams) const;

	// ---- mutations ----
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") FGuid FoundCompany(FName NicheId, const FString& Name, bool bAIOwned = false);
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") void TickEconomyDay();
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Economy") void RegisterNiche(const FMogulNicheParams& Params);

	const TMap<FName, FMogulNicheParams>& GetNiches() const { return Niches; }

private:
	UPROPERTY() TMap<FName, FMogulNicheParams> Niches;

	void SeedDefaultNiches();
	void LoadNichesFromAssets();
	void MarketTick();
	void UpdatePhase();
};
