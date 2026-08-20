// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSoulStateVector.h"
#include "AshenMindscapeSpawnerActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPhantasmsSpawnedSignature, EImprintType, ImprintType, int32, Count);

/**
 * AAshenMindscapeSpawnerActor
 *
 * Spawns phantasm enemies (Ashen Blight Ghouls, Spectral Shroud Manifestations)
 * inside Mindscape collapse volumes based on dominant imprint type (Combat, Identity, Relationship).
 */
UCLASS()
class ASHENOATH_API AAshenMindscapeSpawnerActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenMindscapeSpawnerActor();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Mindscape")
	void SpawnPhantasmsForImprintType(EImprintType ImprintType, int32 SpawnCount = 3);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Mindscape")
	TSubclassOf<APawn> GhoulClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Mindscape")
	float SpawnRadius = 500.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Mindscape|Events")
	FOnPhantasmsSpawnedSignature OnPhantasmsSpawned;
};
