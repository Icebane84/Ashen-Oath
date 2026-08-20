// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMemoryDuelArenaBoundsActor.h"

AAshenMemoryDuelArenaBoundsActor::AAshenMemoryDuelArenaBoundsActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenMemoryDuelArenaBoundsActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenMemoryDuelArenaBoundsActor: Memory duel arena actor active."));
}

void AAshenMemoryDuelArenaBoundsActor::LockArenaBoundaries()
{
	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryDuelArenaBoundsActor: Arena boundaries LOCKED (Radius: %.0fuu)."), ArenaRadius);
}

void AAshenMemoryDuelArenaBoundsActor::UnlockArenaBoundaries()
{
	UE_LOG(LogTemp, Log, TEXT("AAshenMemoryDuelArenaBoundsActor: Arena boundaries UNLOCKED."));
}
