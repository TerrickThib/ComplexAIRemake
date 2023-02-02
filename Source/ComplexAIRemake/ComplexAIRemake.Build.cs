// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ComplexAIRemake : ModuleRules
{
	public ComplexAIRemake(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay",
			"AIModule",
			//GameplayTask
			"NavigationSystem"});
	}
}
