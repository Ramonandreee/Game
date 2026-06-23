// MOGUL (Project ATLAS) — Save Subsystem implementation.
#include "Save/MogulSaveSubsystem.h"
#include "Save/MogulSaveGame.h"
#include "Economy/MogulEconomySubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "MogulLog.h"

bool UMogulSaveSubsystem::SaveToSlot(const FString& SlotName)
{
	UGameInstance* GI = GetGameInstance();
	UMogulEconomySubsystem* Econ = GI ? GI->GetSubsystem<UMogulEconomySubsystem>() : nullptr;
	if (!Econ) { return false; }

	UMogulSaveGame* Save = Cast<UMogulSaveGame>(UGameplayStatics::CreateSaveGameObject(UMogulSaveGame::StaticClass()));
	if (!Save) { return false; }

	Save->SaveVersion = UMogulSaveGame::CurrentVersion;
	Save->SavedAtUtc = FDateTime::UtcNow();
	Save->Day = Econ->Day;
	Save->PhaseLevel = Econ->PhaseLevel;
	Save->Cash = Econ->Cash;
	Save->Market = Econ->Market;
	Save->Companies = Econ->Companies;
	Save->SkillNegotiation = Econ->SkillNegotiation;
	Save->SkillCharisma = Econ->SkillCharisma;
	Save->SkillFinance = Econ->SkillFinance;
	Save->SkillLeadership = Econ->SkillLeadership;
	Save->RepMarket = Econ->RepMarket;
	Save->RepTalent = Econ->RepTalent;
	Save->RepPublic = Econ->RepPublic;
	// NOTE: Agents snapshot wired the same way once AgentSubsystem exposes its registry.

	const bool bOk = UGameplayStatics::SaveGameToSlot(Save, SlotName, 0);
	UE_LOG(LogMogul, Log, TEXT("Save '%s' -> %s (day %d, net %.0f)"), *SlotName, bOk ? TEXT("OK") : TEXT("FAILED"), Save->Day, Econ->GetNetWorth());
	return bOk;
}

bool UMogulSaveSubsystem::LoadFromSlot(const FString& SlotName)
{
	if (!DoesSaveExist(SlotName)) { return false; }

	UMogulSaveGame* Save = Cast<UMogulSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
	if (!Save) { return false; }

	// --- schema migration (docs/10 §7) ---
	if (Save->SaveVersion < UMogulSaveGame::CurrentVersion)
	{
		UE_LOG(LogMogul, Warning, TEXT("Migrating save v%d -> v%d"), Save->SaveVersion, UMogulSaveGame::CurrentVersion);
		// (apply field migrations here as the schema evolves)
		Save->SaveVersion = UMogulSaveGame::CurrentVersion;
	}

	UGameInstance* GI = GetGameInstance();
	UMogulEconomySubsystem* Econ = GI ? GI->GetSubsystem<UMogulEconomySubsystem>() : nullptr;
	if (!Econ) { return false; }

	Econ->Day = Save->Day;
	Econ->PhaseLevel = Save->PhaseLevel;
	Econ->Cash = Save->Cash;
	Econ->Market = Save->Market;
	Econ->Companies = Save->Companies;
	Econ->SkillNegotiation = Save->SkillNegotiation;
	Econ->SkillCharisma = Save->SkillCharisma;
	Econ->SkillFinance = Save->SkillFinance;
	Econ->SkillLeadership = Save->SkillLeadership;
	Econ->RepMarket = Save->RepMarket;
	Econ->RepTalent = Save->RepTalent;
	Econ->RepPublic = Save->RepPublic;

	UE_LOG(LogMogul, Log, TEXT("Loaded '%s' (day %d)"), *SlotName, Econ->Day);
	return true;
}

bool UMogulSaveSubsystem::DoesSaveExist(const FString& SlotName) const
{
	return UGameplayStatics::DoesSaveGameExist(SlotName, 0);
}
