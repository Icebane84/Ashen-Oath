// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AshenOath : ModuleRules
{
	public AshenOath(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"Niagara",
			"DeveloperSettings",
			"Json",
			"JsonUtilities",
			"HTTP",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"NavigationSystem",
			"FieldSystemEngine"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"AshenOath",
			"AshenOath/Core",
			"AshenOath/Soul",
			"AshenOath/Memory",
			"AshenOath/Companions",
			"AshenOath/Combat",
			"AshenOath/Narrative",
			"AshenOath/UI",
			"AshenOath/Audio",
			"AshenOath/World",
			"AshenOath/Orchestration",
			"AshenOath/QA",
			"AshenOath/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
