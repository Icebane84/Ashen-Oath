// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenTraumaSomaticsMasterBridge.h"

UAshenTraumaSomaticsMasterBridge::UAshenTraumaSomaticsMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTraumaSomaticsMasterBridge::BroadcastSomaticEvolution(ETraumaSomaticStage Stage, float VeinCorruption)
{
	OnSomaticEvolutionBroadcaster.Broadcast(Stage, VeinCorruption);
}
