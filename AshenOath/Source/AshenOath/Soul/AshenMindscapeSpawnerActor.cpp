// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenMindscapeSpawnerActor.h"
#include "AshenBlightGhoul.h"
#include "Engine/World.h"

AAshenMindscapeSpawnerActor::AAshenMindscapeSpawnerActor()
{
	PrimaryActorTick.bCanEverTick = false;
	SpawnRadius = 500.0f;
}

void AAshenMindscapeSpawnerActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenMindscapeSpawnerActor::SpawnPhantasmsForImprintType(EImprintType ImprintType, int32 SpawnCount)
{
	UWorld* World = GetWorld();
	if (!World) return;

	FVector Origin = GetActorLocation();

	for (int32 i = 0; i < SpawnCount; ++i)
	{
		FVector RandomOffset = FMath::VRand() * FMath::RandRange(100.0f, SpawnRadius);
		RandomOffset.Z = 0.0f; // Keep ground level
		FVector SpawnLoc = Origin + RandomOffset;

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		AAshenBlightGhoul* Ghoul = World->SpawnActor<AAshenBlightGhoul>(AAshenBlightGhoul::StaticClass(), SpawnLoc, FRotator::ZeroRotator, SpawnParams);
		if (Ghoul)
		{
			UE_LOG(LogTemp, Warning, TEXT("AAshenMindscapeSpawnerActor: Spawned Mindscape Phantasm '%s' at %s"),
				*Ghoul->GetName(), *SpawnLoc.ToString());
		}
	}

	OnPhantasmsSpawned.Broadcast(ImprintType, SpawnCount);
}
