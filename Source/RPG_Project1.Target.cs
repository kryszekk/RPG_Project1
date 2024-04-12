// All rights reserved

using UnrealBuildTool;
using System.Collections.Generic;

public class RPG_Project1Target : TargetRules
{
	public RPG_Project1Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "RPG_Project1" } );
	}
}
