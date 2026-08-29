// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenCSEMasterBridge.h"

UAshenCSEMasterBridge::UAshenCSEMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCSEMasterBridge::BroadcastCSEState(
	float DissonanceIndex,
	ECognitiveDissonanceTier Tier)
{
	OnCSEBroadcaster.Broadcast(DissonanceIndex, Tier);
}
