// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenParasiticBladeMasterBridge.h"

UAshenParasiticBladeMasterBridge::UAshenParasiticBladeMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenParasiticBladeMasterBridge::BroadcastBladeMass(float NewMassKg)
{
	OnBladeMassBroadcaster.Broadcast(NewMassKg);
}
