// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AventuraUSFX2026GL1 : ModuleRules
{
	public AventuraUSFX2026GL1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
