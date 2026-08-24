// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenChaosNavmeshSaveGameAdapter.generated.h"

/**
 * UAshenChaosNavmeshSaveGameAdapter
 * 
 * Serializes and restores fractured pillar destruction states and cleared navmesh obstacle locations.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenChaosNavmeshSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenChaosNavmeshSaveGameAdapter();

	/** Packages Chaos navmesh destruction state for save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageChaosState(int32 FracturedPillarsCount, int32 ClearedDebrisCount, float TotalDebrisMassKg);

	/** Restores Chaos navmesh destruction state from save */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreChaosState(int32& OutFracturedPillars, int32& OutClearedDebris, float& OutTotalMassKg);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedFracturedPillarsCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedClearedDebrisCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedTotalDebrisMassKg = 0.0f;

private:
	bool bHasSavedData = false;
};
