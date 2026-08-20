// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenMindscapeBossSpawnerActor.h"
#include "AshenShroudKnight.h"
#include "Engine/World.h"

AAshenMindscapeBossSpawnerActor::AAshenMindscapeBossSpawnerActor()
{
	PrimaryActorTick.bCanEverTick = false;
	BossClass = AAshenShroudKnight::StaticClass();
}

void AAshenMindscapeBossSpawnerActor::BeginPlay()
{
	Super::BeginPlay();
}

AAshenShroudKnight* AAshenMindscapeBossSpawnerActor::SpawnBossPhantasm(FVector Location)
{
	UWorld* World = GetWorld();
	if (!World || !BossClass) return nullptr;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AAshenShroudKnight* BossPhantasm = World->SpawnActor<AAshenShroudKnight>(BossClass, Location, FRotator::ZeroRotator, SpawnParams);
	if (BossPhantasm)
	{
		OnBossPhantasmSpawned.Broadcast(BossPhantasm);
		UE_LOG(LogTemp, Warning, TEXT("AAshenMindscapeBossSpawnerActor: Spectral Boss Phantasm '%s' spawned for catastrophic collapse!"), *BossPhantasm->GetName());
	}

	return BossPhantasm;
}
