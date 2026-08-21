// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenScenario1SaveGameAdapter.generated.h"

/**
 * UAshenScenario1SaveGameAdapter
 * 
 * Serializes and restores Scenario 1 mission completion state, Malakor defeat flag, and debt mutations.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario1SaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario1SaveGameAdapter();

	/** Packages Scenario 1 progress for save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageScenario1State(bool bChapelCleared, float ResultingIsolation, float ResultingDebt);

	/** Restores Scenario 1 progress from save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreScenario1State(bool& OutChapelCleared, float& OutIsolation, float& OutDebt);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedChapelCleared = false;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedIsolation = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedDebt = 0.0f;

private:
	bool bHasSavedData = false;
};
