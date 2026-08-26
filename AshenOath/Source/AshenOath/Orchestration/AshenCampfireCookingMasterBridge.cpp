// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenCampfireCookingMasterBridge.h"

UAshenCampfireCookingMasterBridge::UAshenCampfireCookingMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCampfireCookingMasterBridge::BroadcastCookingState(const FCampfireStewStateVector& State)
{
	OnCookingBroadcaster.Broadcast(State.PotState, State.TemperatureCelsius);
}
