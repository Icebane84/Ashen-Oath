// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEnemySpawnDirectorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWaveSpawnedSignature, int32, WaveIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllWavesCompleteSignature);

/**
 * UAshenEnemySpawnDirectorComponent
 *
 * Threat-budget enemy wave spawner. Manages wave spawning at designated
 * spawn points with configurable threat budgets per wave. Uses
 * UKismetSystemLibrary::SphereOverlapActors to skip spawning in occupied zones.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEnemySpawnDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenEnemySpawnDirectorComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Spawning")
	void StartEncounter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Spawning")
	void SpawnNextWave();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Spawning")
	void RegisterEnemyKilled();

	UFUNCTION(BlueprintPure, Category = "AshenOath|Spawning")
	bool IsEncounterActive() const { return bEncounterActive; }

	// --- Configuration ---
	/** Subclass of enemy to spawn each wave. Set in BP. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Spawning")
	TSubclassOf<AActor> EnemyClass;

	/** Threat budget (number of enemies) per wave. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Spawning")
	int32 ThreatBudgetPerWave = 4;

	/** Total number of waves before encounter ends. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Spawning")
	int32 TotalWaves = 3;

	/** Radius used for overlap check before spawning at a point. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Spawning")
	float SpawnOverlapCheckRadius = 150.0f;

	/** Registered spawn point locations. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Spawning")
	TArray<FVector> SpawnLocations;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Spawning|Events")
	FOnWaveSpawnedSignature OnWaveSpawned;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Spawning|Events")
	FOnAllWavesCompleteSignature OnAllWavesComplete;

private:
	bool bEncounterActive = false;
	int32 CurrentWave = 0;
	int32 AliveEnemyCount = 0;
};
