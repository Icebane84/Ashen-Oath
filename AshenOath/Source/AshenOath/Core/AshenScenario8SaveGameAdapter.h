// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenScenario8SaveGameAdapter.generated.h"

/**
 * UAshenScenario8SaveGameAdapter
 * 
 * Serializes Scenario 8 state: remaining torch fuel, light radius, discovered catacomb nodes, and lurker defeated count.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario8SaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario8SaveGameAdapter();

	/** Packages Scenario 8 state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageScenario8State(float RemainingFuel01, float FinalLightRadiusUU, int32 LurkersDefeated, int32 DiscoveredChasms);

	/** Restores Scenario 8 state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreScenario8State(float& OutFuel01, float& OutLightRadiusUU, int32& OutLurkers, int32& OutChasms);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedRemainingFuel01 = 1.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedFinalLightRadiusUU = 800.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedLurkersDefeated = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedDiscoveredChasms = 0;

private:
	bool bHasSavedData = false;
};
