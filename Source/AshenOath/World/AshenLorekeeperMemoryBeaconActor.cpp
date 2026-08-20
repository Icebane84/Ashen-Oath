// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenLorekeeperMemoryBeaconActor.h"

AAshenLorekeeperMemoryBeaconActor::AAshenLorekeeperMemoryBeaconActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenLorekeeperMemoryBeaconActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenLorekeeperMemoryBeaconActor: Memory Beacon initialized."));
}

bool AAshenLorekeeperMemoryBeaconActor::IgniteMemoryBeacon(FName EchoID)
{
	bIsBeaconIgnited = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenLorekeeperMemoryBeaconActor: MEMORY BEACON IGNITED! Echo '%s' archived into Lorekeeper Constellation."),
		*EchoID.ToString());
	return true;
}
