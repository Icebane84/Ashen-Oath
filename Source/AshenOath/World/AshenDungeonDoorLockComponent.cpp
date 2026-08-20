// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 226: Ashen Dungeon Door Lock Component

#include "AshenDungeonDoorLockComponent.h"

UAshenDungeonDoorLockComponent::UAshenDungeonDoorLockComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	RequiredKeyID = FName("Key_SanctuaryGate");
	bIsLocked = true;
}

void UAshenDungeonDoorLockComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenDungeonDoorLockComponent::TryUnlockWithKey(FName PlayerKeyID)
{
	if (!bIsLocked) return true; // Already unlocked

	if (PlayerKeyID != RequiredKeyID)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonDoorLockComponent: Cannot unlock door — key '%s' does not match required key '%s'."),
			*PlayerKeyID.ToString(), *RequiredKeyID.ToString());
		return false;
	}

	bIsLocked = false;
	OnDoorUnlocked.Broadcast(PlayerKeyID);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonDoorLockComponent: DOOR UNLOCKED using key '%s'!"), *PlayerKeyID.ToString());
	return true;
}
