// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 256: Ashen Dungeon Lever Switch Component

#include "AshenDungeonLeverSwitchComponent.h"

UAshenDungeonLeverSwitchComponent::UAshenDungeonLeverSwitchComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	LeverID = FName("Lever_Default");
	bIsActivated = false;
}

void UAshenDungeonLeverSwitchComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenDungeonLeverSwitchComponent::ToggleLever()
{
	bIsActivated = !bIsActivated;
	OnLeverToggled.Broadcast(LeverID, bIsActivated);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonLeverSwitchComponent: LEVER '%s' TOGGLED -> %s."),
		*LeverID.ToString(), bIsActivated ? TEXT("ACTIVATED") : TEXT("DEACTIVATED"));

	return bIsActivated;
}
