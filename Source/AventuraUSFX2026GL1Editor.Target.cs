// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class AventuraUSFX2026GL1EditorTarget : TargetRules
{
	public AventuraUSFX2026GL1EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("AventuraUSFX2026GL1");
	}
}
