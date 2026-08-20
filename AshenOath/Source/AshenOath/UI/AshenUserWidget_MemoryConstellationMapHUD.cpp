// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_MemoryConstellationMapHUD.h"

void UAshenUserWidget_MemoryConstellationMapHUD::UpdateConstellationMap(float Zoom, int32 GoldConduits, int32 ObsidianFractures)
{
	MapZoomLevel = FMath::Clamp(Zoom, 0.0f, 1.0f);
	ActiveGoldLeyConduits = GoldConduits;
	ActiveObsidianFractures = ObsidianFractures;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_MemoryConstellationMapHUD: Map Zoom: %.2f | Gold Conduits: %d | Obsidian Fractures: %d"),
		MapZoomLevel, ActiveGoldLeyConduits, ActiveObsidianFractures);
}
