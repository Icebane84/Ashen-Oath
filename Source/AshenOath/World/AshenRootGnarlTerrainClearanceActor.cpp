// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenRootGnarlTerrainClearanceActor.h"

AAshenRootGnarlTerrainClearanceActor::AAshenRootGnarlTerrainClearanceActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenRootGnarlTerrainClearanceActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenRootGnarlTerrainClearanceActor: Entropic root blockade active."));
}

void AAshenRootGnarlTerrainClearanceActor::ClearRootBlockade()
{
	bIsPathCleared = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenRootGnarlTerrainClearanceActor: SUBTERRANEAN SEVERANCE! Root blockade burned away; path open."));
	Destroy();
}
