// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 442: Ashen Procedural Encounter HUD UMG Widget

#include "AshenUserWidget_ProceduralEncounterHUD.h"

void UAshenUserWidget_ProceduralEncounterHUD::UpdateEncounterHUDDisplay(int32 ThreatTier, int32 EnemyCount)
{
	DisplayedThreatTier = ThreatTier;
	DisplayedEnemyCount = EnemyCount;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_ProceduralEncounterHUD: Encounter HUD updated — Threat Tier %d (%d Enemies)."),
		ThreatTier, EnemyCount);
}
