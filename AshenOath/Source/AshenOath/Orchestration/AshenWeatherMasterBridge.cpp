// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenWeatherMasterBridge.h"

UAshenWeatherMasterBridge::UAshenWeatherMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenWeatherMasterBridge::BroadcastWeatherState(
	EWeatherHazardState NewState,
	float Temperature)
{
	OnWeatherBroadcaster.Broadcast(NewState, Temperature);
}
