// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenOathbringerStanceMasterBridge.h"

UAshenOathbringerStanceMasterBridge::UAshenOathbringerStanceMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenOathbringerStanceMasterBridge::BroadcastStanceUpdate(
	EOathbringerMartialStance Stance,
	const FOathbringerStanceKinematics& Kinematics)
{
	OnStanceBroadcaster.Broadcast(Stance, Kinematics);
}
