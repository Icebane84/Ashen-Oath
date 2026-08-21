// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Orchestration/AshenRunicReliquaryMasterBridge.h"

UAshenRunicReliquaryMasterBridge::UAshenRunicReliquaryMasterBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRunicReliquaryMasterBridge::BroadcastForgeCompleted(bool bSuccess)
{
	OnRunicForgeCompleted.Broadcast(bSuccess);
}

void UAshenRunicReliquaryMasterBridge::BroadcastWeaponAttunement(const FSoulForgeWeaponState& NewState)
{
	OnWeaponAttunementUpdated.Broadcast(NewState);
}
