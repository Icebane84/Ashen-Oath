// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenDynamicArenaBoundaryActor.h"

AAshenDynamicArenaBoundaryActor::AAshenDynamicArenaBoundaryActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsArenaLocked = false;
}
void AAshenDynamicArenaBoundaryActor::BeginPlay() { Super::BeginPlay(); }

void AAshenDynamicArenaBoundaryActor::SetArenaLockState(bool bLock)
{
	bIsArenaLocked = bLock;
	UE_LOG(LogTemp, Warning, TEXT("AAshenDynamicArenaBoundaryActor: Arena Boundary Barrier: %s!"),
		bIsArenaLocked ? TEXT("LOCKED") : TEXT("UNLOCKED"));
}
