// MOGUL (Project ATLAS) — Save Subsystem (docs/10 §7).
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MogulSaveSubsystem.generated.h"

UCLASS()
class MOGUL_API UMogulSaveSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MOGUL|Save")
	bool SaveToSlot(const FString& SlotName = TEXT("MOGUL_Slot0"));

	UFUNCTION(BlueprintCallable, Category = "MOGUL|Save")
	bool LoadFromSlot(const FString& SlotName = TEXT("MOGUL_Slot0"));

	UFUNCTION(BlueprintCallable, Category = "MOGUL|Save")
	bool DoesSaveExist(const FString& SlotName = TEXT("MOGUL_Slot0")) const;
};
