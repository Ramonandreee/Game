// MOGUL (Project ATLAS) — base Game Mode.
#include "Core/MogulGameModeBase.h"

AMogulGameModeBase::AMogulGameModeBase()
{
	// Player pawn / controller classes are set in the editor (or a BP child).
	// The first-person walkable navigation is prototyped in /world (Three.js);
	// here it will be a Character + EnhancedInput in production.
	PrimaryActorTick.bCanEverTick = false;
}
