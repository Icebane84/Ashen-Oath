// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 248: Ashen Dungeon Elevator Component

#include "AshenDungeonElevatorComponent.h"

UAshenDungeonElevatorComponent::UAshenDungeonElevatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalFloors = 3;
	CurrentFloor = 0;
	bIsMoving = false;
}

void UAshenDungeonElevatorComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenDungeonElevatorComponent::MoveToFloor(int32 TargetFloorIndex)
{
	if (bIsMoving || TargetFloorIndex < 0 || TargetFloorIndex >= TotalFloors || TargetFloorIndex == CurrentFloor)
	{
		return false;
	}

	CurrentFloor = TargetFloorIndex;
	bIsMoving = false; // Synchronous completion for logic simulation

	const FVector Location = GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;
	OnFloorReached.Broadcast(CurrentFloor, Location);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonElevatorComponent: ELEVATOR ARRIVED at Floor %d / %d."), CurrentFloor + 1, TotalFloors);
	return true;
}
