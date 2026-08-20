// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 164: Ashen Enemy Spawn Director Component

#include "AshenEnemySpawnDirectorComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/World.h"

UAshenEnemySpawnDirectorComponent::UAshenEnemySpawnDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ThreatBudgetPerWave = 4;
	TotalWaves = 3;
	SpawnOverlapCheckRadius = 150.0f;
	bEncounterActive = false;
	CurrentWave = 0;
	AliveEnemyCount = 0;
}

void UAshenEnemySpawnDirectorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenEnemySpawnDirectorComponent::StartEncounter()
{
	if (bEncounterActive) return;

	bEncounterActive = true;
	CurrentWave = 0;
	AliveEnemyCount = 0;

	UE_LOG(LogTemp, Warning, TEXT("UAshenEnemySpawnDirectorComponent: Encounter STARTED — %d waves, %d threat budget per wave."),
		TotalWaves, ThreatBudgetPerWave);

	SpawnNextWave();
}

void UAshenEnemySpawnDirectorComponent::SpawnNextWave()
{
	if (!bEncounterActive) return;
	if (CurrentWave >= TotalWaves)
	{
		bEncounterActive = false;
		OnAllWavesComplete.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("UAshenEnemySpawnDirectorComponent: All %d waves complete — encounter ENDED."), TotalWaves);
		return;
	}

	CurrentWave++;
	int32 SpawnedCount = 0;

	for (int32 i = 0; i < ThreatBudgetPerWave && i < SpawnLocations.Num(); ++i)
	{
		const FVector& SpawnPt = SpawnLocations[i];

		// Spatial overlap check — skip occupied spawn points (PHOENIX CODEX mandate)
		TArray<AActor*> OverlappingActors;
		UKismetSystemLibrary::SphereOverlapActors(
			GetWorld(),
			SpawnPt,
			SpawnOverlapCheckRadius,
			TArray<TEnumAsByte<EObjectTypeQuery>>(),
			AActor::StaticClass(),
			TArray<AActor*>(),
			OverlappingActors
		);

		if (OverlappingActors.Num() > 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("UAshenEnemySpawnDirectorComponent: Spawn point %d occupied — skipping."), i);
			continue;
		}

		if (EnemyClass && GetWorld())
		{
			FActorSpawnParameters Params;
			Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
			AActor* Enemy = GetWorld()->SpawnActor<AActor>(EnemyClass, SpawnPt, FRotator::ZeroRotator, Params);
			if (Enemy)
			{
				SpawnedCount++;
				AliveEnemyCount++;
			}
		}
	}

	OnWaveSpawned.Broadcast(CurrentWave);
	UE_LOG(LogTemp, Warning, TEXT("UAshenEnemySpawnDirectorComponent: Wave %d spawned %d enemies."), CurrentWave, SpawnedCount);
}

void UAshenEnemySpawnDirectorComponent::RegisterEnemyKilled()
{
	AliveEnemyCount = FMath::Max(0, AliveEnemyCount - 1);
	UE_LOG(LogTemp, Log, TEXT("UAshenEnemySpawnDirectorComponent: Enemy killed — %d alive remaining."), AliveEnemyCount);

	if (AliveEnemyCount <= 0 && bEncounterActive)
	{
		SpawnNextWave();
	}
}
