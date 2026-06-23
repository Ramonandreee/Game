// MOGUL (Project ATLAS) — Event Bus (Event-Driven Architecture, docs/10 §3.2).
// Systems emit/subscribe to named events instead of calling each other directly.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MogulEventBus.generated.h"

// EventId examples: "EmployeeResigned", "CompanyAcquired", "MarketCrash", "ScandalLeaked".
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMogulOnEvent, FName, EventId, const FString&, Payload);

UCLASS()
class MOGUL_API UMogulEventBus : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "MOGUL|Events")
	FMogulOnEvent OnEvent;

	UFUNCTION(BlueprintCallable, Category = "MOGUL|Events")
	void Emit(FName EventId, const FString& Payload);
};
