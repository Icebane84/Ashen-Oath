// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenConstellationWaypointActor.h"

AAshenConstellationWaypointActor::AAshenConstellationWaypointActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsWaypointHarmonized = false;
}
void AAshenConstellationWaypointActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenConstellationWaypointActor::HarmonizeWaypoint(AActor* InstigatingPlayer)
{
	if (!InstigatingPlayer) return false;
	bIsWaypointHarmonized = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenConstellationWaypointActor: Waypoint harmonized into active Memory Constellation graph!"));
	return true;
}
