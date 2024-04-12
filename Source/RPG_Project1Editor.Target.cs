// All rights reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class RPG_Project1EditorTarget : TargetRules
{
	public RPG_Project1EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "RPG_Project1" } );
	}
}
