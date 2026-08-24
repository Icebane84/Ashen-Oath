// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenScenario7SaveGameAdapter.generated.h"

/**
 * UAshenScenario7SaveGameAdapter
 * 
 * Serializes Scenario 7 progress: maximum caldera temperature survived, blade tempering state, and heat exhaustion records.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario7SaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario7SaveGameAdapter();

	/** Packages Scenario 7 state for SaveGame file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageScenario7State(
		float MaxTempSurvivedC,
		float FinalHeatExhaustion,
		float FinalBladeTempC,
		ETemperedBladeState FinalBladeState);

	/** Restores Scenario 7 state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreScenario7State(
		float& OutMaxTempC,
		float& OutHeatExhaustion,
		float& OutBladeTempC,
		ETemperedBladeState& OutBladeState);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedMaxTempSurvivedC = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedFinalHeatExhaustion = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedFinalBladeTempC = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	ETemperedBladeState SavedFinalBladeState = ETemperedBladeState::ColdSteel;

private:
	bool bHasSavedData = false;
};
