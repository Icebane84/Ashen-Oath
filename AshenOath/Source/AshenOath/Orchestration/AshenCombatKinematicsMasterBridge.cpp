// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenCombatKinematicsMasterBridge.h"

UAshenCombatKinematicsMasterBridge::UAshenCombatKinematicsMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCombatKinematicsMasterBridge::BroadcastKinematicsState(
	EAshenWeightClass WeightClass,
	float WeightRatio)
{
	OnKinematicsBroadcaster.Broadcast(WeightClass, WeightRatio);
}
