// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenOathbringerMirrorEnemySpawner.h"

void UAshenOathbringerMirrorEnemySpawner::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerMirrorEnemySpawner: Mirror Enemy Spawner initialized."));
}

void UAshenOathbringerMirrorEnemySpawner::Deinitialize() { Super::Deinitialize(); }

bool UAshenOathbringerMirrorEnemySpawner::SpawnOathbringerMirrorPhantom(FVector SpawnLocation)
{
	bMirrorPhantomActive = true;
	UE_LOG(LogTemp, Error, TEXT("UAshenOathbringerMirrorEnemySpawner: CORRUPTED OATHBRINGER MIRROR PHANTOM SPAWNED at Mindscape location (%f, %f, %f)!"),
		SpawnLocation.X, SpawnLocation.Y, SpawnLocation.Z);
	return true;
}
