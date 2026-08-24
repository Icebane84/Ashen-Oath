// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenScenario9SaveGameAdapter.generated.h"

/**
 * UAshenScenario9SaveGameAdapter
 * 
 * Serializes Scenario 9 state: unlocked islands, bridges activated, highest altitude traversed, and automatons crushed.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario9SaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario9SaveGameAdapter();

	/** Packages Scenario 9 state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageScenario9State(float FinalGravityScale, float HighestAltitudeUU, int32 BridgesActivated, int32 AutomatonsCrushed);

	/** Restores Scenario 9 state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreScenario9State(float& OutGravityScale, float& OutAltitudeUU, int32& OutBridges, int32& OutAutomatons);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedGravityScale = 0.35f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedHighestAltitudeUU = 8500.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedBridgesActivated = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedAutomatonsCrushed = 0;

private:
	bool bHasSavedData = false;
};
