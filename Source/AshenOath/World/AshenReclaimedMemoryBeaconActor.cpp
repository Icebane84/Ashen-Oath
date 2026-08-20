// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenReclaimedMemoryBeaconActor.h"

AAshenReclaimedMemoryBeaconActor::AAshenReclaimedMemoryBeaconActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenReclaimedMemoryBeaconActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenReclaimedMemoryBeaconActor: Reclaimed Memory Beacon initialized."));
}

void AAshenReclaimedMemoryBeaconActor::IgniteMemoryBeacon()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenReclaimedMemoryBeaconActor: Reclaimed Memory Beacon ignited for memory '%s'!"), *BoundMemoryID.ToString());
}
