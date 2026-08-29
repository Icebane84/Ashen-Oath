// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenSanctuarySurvivalMasterBridge.h"

UAshenSanctuarySurvivalMasterBridge::UAshenSanctuarySurvivalMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSanctuarySurvivalMasterBridge::BroadcastShelterUpdate(
	EThermalShelterTier Tier,
	const FShelterThermodynamicState& State)
{
	OnShelterBroadcaster.Broadcast(Tier, State);
}
