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

		// Mass/StateTree/SmartObjects stay enabled as PLUGINS in the .uproject, but
		// only become module dependencies when code that uses them lands. This keeps
		// the first build green across engine-version module renames (e.g. StructUtils
		// was absorbed into Core in 5.5+ and no longer resolves as a module in 5.6).
		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
