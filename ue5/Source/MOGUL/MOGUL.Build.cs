// MOGUL (Project ATLAS) — runtime module build rules.
using UnrealBuildTool;

public class MOGUL : ModuleRules
{
	public MOGUL(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks"
		});

		// Mass / AI / procedural systems (see docs/10-TECHNICAL-ARCHITECTURE.md).
		// Kept as Private so the spine compiles even before these are wired into gameplay.
		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"MassEntity",
			"MassCommon",
			"MassSpawner",
			"StructUtils",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"SmartObjectsModule"
		});
	}
}
