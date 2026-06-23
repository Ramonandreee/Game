// MOGUL (Project ATLAS) — editor target.
using UnrealBuildTool;
using System.Collections.Generic;

public class MOGULEditorTarget : TargetRules
{
	public MOGULEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.AddRange(new string[] { "MOGUL" });
	}
}
