// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 261: Ashen Dungeon Pressure Plate Component

#include "AshenDungeonPressurePlateComponent.h"

UAshenDungeonPressurePlateComponent::UAshenDungeonPressurePlateComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	PlateID = FName("Plate_01");
	bIsDepressed = false;
	OverlappingActorCount = 0;
}

void UAshenDungeonPressurePlateComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDungeonPressurePlateComponent::OnActorSteppedOn(AActor* SteppingActor)
{
	OverlappingActorCount++;
	if (!bIsDepressed && OverlappingActorCount > 0)
	{
		bIsDepressed = true;
		OnPlateStateChanged.Broadcast(PlateID, true);

		UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonPressurePlateComponent: PRESSURE PLATE '%s' DEPRESSED by '%s'."),
			*PlateID.ToString(), SteppingActor ? *SteppingActor->GetName() : TEXT("Unknown"));
	}
}

void UAshenDungeonPressurePlateComponent::OnActorSteppedOff(AActor* SteppingActor)
{
	OverlappingActorCount = FMath::Max(0, OverlappingActorCount - 1);
	if (bIsDepressed && OverlappingActorCount == 0)
	{
		bIsDepressed = false;
		OnPlateStateChanged.Broadcast(PlateID, false);

		UE_LOG(LogTemp, Log, TEXT("UAshenDungeonPressurePlateComponent: Pressure plate '%s' released."), *PlateID.ToString());
	}
}
