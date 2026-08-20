// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMindscapeBossSpawnerActor.generated.h"

class AAshenShroudKnight;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBossPhantasmSpawnedSignature, AAshenShroudKnight*, BossInstance);

/**
 * AAshenMindscapeBossSpawnerActor
 *
 * Spawns spectral boss phantasms (Shadow Shroud Knight) during Stage 4 catastrophic Mindscape collapse phases.
 */
UCLASS()
class ASHENOATH_API AAshenMindscapeBossSpawnerActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMindscapeBossSpawnerActor();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Mindscape")
	AAshenShroudKnight* SpawnBossPhantasm(FVector Location);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Mindscape")
	TSubclassOf<AAshenShroudKnight> BossClass;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Mindscape|Events")
	FOnBossPhantasmSpawnedSignature OnBossPhantasmSpawned;
};
