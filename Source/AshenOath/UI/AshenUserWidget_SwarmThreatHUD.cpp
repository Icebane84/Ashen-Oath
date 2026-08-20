// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 482: Ashen Swarm Threat HUD UMG Widget

#include "AshenUserWidget_SwarmThreatHUD.h"

void UAshenUserWidget_SwarmThreatHUD::UpdateSwarmHUDDisplay(int32 SwarmCount, float FlankMultiplier)
{
	DisplayedSwarmCount = SwarmCount;
	DisplayedFlankMultiplier = FlankMultiplier;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_SwarmThreatHUD: Swarm Threat HUD updated — Swarm Count %d (Flank Multiplier: %.2fx)."),
		SwarmCount, FlankMultiplier);
}
