// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenArenaHazardGridComponent.h"

UAshenArenaHazardGridComponent::UAshenArenaHazardGridComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveHazards.Empty();
}
void UAshenArenaHazardGridComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenArenaHazardGridComponent::SpawnHazardZone(FVector Location, float Radius, EArenaHazardType Type)
{
	FArenaHazardZoneData NewZone;
	NewZone.Location = Location;
	NewZone.Radius = Radius;
	NewZone.HazardType = Type;
	NewZone.bIsHazardActive = true;

	ActiveHazards.Add(NewZone);
	UE_LOG(LogTemp, Warning, TEXT("UAshenArenaHazardGridComponent: SPAWNED ARENA HAZARD: Type %d at %s (Radius: %.1fuu)!"),
		static_cast<int32>(Type), *Location.ToString(), Radius);
	return true;
}
