// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 394: Ashen Mindscape Dungeon Map UMG Widget

#include "AshenUserWidget_MindscapeDungeonMap.h"

void UAshenUserWidget_MindscapeDungeonMap::UpdateDungeonMapDisplay(int32 DungeonSeed, FName LayoutTheme)
{
	DisplayedSeed = DungeonSeed;
	DisplayedTheme = LayoutTheme;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MindscapeDungeonMap: Mindscape Dungeon Map UI updated — Seed: %d, Theme: '%s'."),
		DungeonSeed, *LayoutTheme.ToString());
}
