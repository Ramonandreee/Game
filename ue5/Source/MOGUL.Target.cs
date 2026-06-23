// MOGUL (Project ATLAS) — game target.
using UnrealBuildTool;
using System.Collections.Generic;

public class MOGULTarget : TargetRules
{
	public MOGULTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.AddRange(new string[] { "MOGUL" });
	}
}
