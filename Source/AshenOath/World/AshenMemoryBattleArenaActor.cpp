// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMemoryBattleArenaActor.h"

AAshenMemoryBattleArenaActor::AAshenMemoryBattleArenaActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenMemoryBattleArenaActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenMemoryBattleArenaActor: Memory Battle Arena initialized."));
}

void AAshenMemoryBattleArenaActor::ShiftArenaGeometry(float IntensityDelta)
{
	ArenaIntegrity = FMath::Clamp(ArenaIntegrity - IntensityDelta, 0.0f, 1.0f);
	if (OnArenaStateShifted.IsBound())
	{
		OnArenaStateShifted.Broadcast(ArenaIntegrity);
	}
	UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryBattleArenaActor: Arena geometry shifted! Integrity now %.2f"), ArenaIntegrity);
}
