// MOGUL (Project ATLAS) — base Game Mode.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MogulGameModeBase.generated.h"

UCLASS()
class MOGUL_API AMogulGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMogulGameModeBase();

protected:
	// Guarantees the Meridian world rig (photoreal sky/post + greybox city)
	// exists in levels that ship without a sky — an Empty Level "just works".
	virtual void BeginPlay() override;
};
