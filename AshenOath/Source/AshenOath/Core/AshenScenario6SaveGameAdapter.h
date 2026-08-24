// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenScenario6SaveGameAdapter.generated.h"

/**
 * UAshenScenario6SaveGameAdapter
 * 
 * Serializes and restores Scenario 6 quest progress, hearth ignition state, and lowest survived temperature.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario6SaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario6SaveGameAdapter();

	/** Packages Scenario 6 state for saving */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageScenario6State(float HearthIgnition, float Frostbite, float LowestTempCelsius, bool bSanctuaryComplete);

	/** Restores Scenario 6 state from save */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreScenario6State(float& OutHearthIgnition, float& OutFrostbite, float& OutLowestTemp, bool& OutSanctuaryComplete);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedHearthIgnition = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedFrostbite = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedLowestTempCelsius = -15.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedSanctuaryComplete = false;

private:
	bool bHasSavedData = false;
};
