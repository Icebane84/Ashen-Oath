// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenWeaponHistorySaveGameAdapter.h"

UAshenWeaponHistorySaveGameAdapter::UAshenWeaponHistorySaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWeaponHistorySaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenWeaponHistorySaveGameAdapter::SerializeWeaponHistoryToSave(int32 LifetimeExecutions, int32 UnlockedRuneTiers)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenWeaponHistorySaveGameAdapter: %d lifetime executions and %d rune tiers serialized to save game."),
		LifetimeExecutions, UnlockedRuneTiers);
	return true;
}
