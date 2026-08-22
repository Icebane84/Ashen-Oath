// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenScenario5SaveGameAdapter.generated.h"

/**
 * UAshenScenario5SaveGameAdapter
 * 
 * Serializes and restores Scenario 5 completion state, gas pockets detonated, and Unchained frenzy stats.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario5SaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario5SaveGameAdapter();

	/** Packages Scenario 5 progress for save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageScenario5State(bool bMireCleared, int32 GasPocketsDetonated, bool bZeroDowned);

	/** Restores Scenario 5 progress from save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreScenario5State(bool& OutMireCleared, int32& OutGasPocketsDetonated, bool& OutZeroDowned);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedMireCleared = false;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedGasPocketsDetonated = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedZeroDowned = true;

private:
	bool bHasSavedData = false;
};
