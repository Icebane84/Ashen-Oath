// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenGhostbloomTripwireAnchorActor.h"

AAshenGhostbloomTripwireAnchorActor::AAshenGhostbloomTripwireAnchorActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsTripwireArmed = false;
}
void AAshenGhostbloomTripwireAnchorActor::BeginPlay() { Super::BeginPlay(); }

void AAshenGhostbloomTripwireAnchorActor::ArmTripwire()
{
	bIsTripwireArmed = true;
	UE_LOG(LogTemp, Log, TEXT("AAshenGhostbloomTripwireAnchorActor: Tripwire Armed."));
}

void AAshenGhostbloomTripwireAnchorActor::TriggerTripwire()
{
	if (!bIsTripwireArmed) return;
	bIsTripwireArmed = false;
	UE_LOG(LogTemp, Warning, TEXT("AAshenGhostbloomTripwireAnchorActor: TRIPWIRE TRIPPED! Detonating Ghostbloom Flash Flare!"));
}
