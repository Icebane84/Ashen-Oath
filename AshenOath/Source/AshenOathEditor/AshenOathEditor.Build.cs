// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

using UnrealBuildTool;

public class AshenOathEditor : ModuleRules
{
	public AshenOathEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"AshenOath"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"UnrealEd",
				"BlueprintGraph",
				"Kismet",
				"KismetCompiler",
				"GameplayTags",
				"GameplayTagsEditor",
				"AssetTools",
				"EditorSubsystem",
				"Slate",
				"SlateCore"
			}
		);
	}
}
