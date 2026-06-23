// MOGUL (Project ATLAS) — Game Instance.
// Owns the lifetime of the global subsystems (Economy / Agents / Simulation / Save).
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MogulGameInstance.generated.h"

UCLASS()
class MOGUL_API UMogulGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Shutdown() override;
};
