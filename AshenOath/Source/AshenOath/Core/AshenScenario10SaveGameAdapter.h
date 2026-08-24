// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenScenario10SaveGameAdapter.generated.h"

/**
 * UAshenScenario10SaveGameAdapter
 * 
 * Serializes Scenario 10 and Grand Campaign completion state: chosen ending, final trust, integration debt, and NG+ unlock flags.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario10SaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario10SaveGameAdapter();

	/** Packages Scenario 10 endgame state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageScenario10State(EZenithConsequenceEnding Ending, float FinalTrust01, float FinalDebt01, bool bNewGamePlusUnlocked);

	/** Restores Scenario 10 endgame state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreScenario10State(EZenithConsequenceEnding& OutEnding, float& OutTrust01, float& OutDebt01, bool& OutNGPlus);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EZenithConsequenceEnding SavedEnding = EZenithConsequenceEnding::RadiantTransfiguration;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedFinalTrust01 = 0.85f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedFinalDebt01 = 0.20f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedNewGamePlusUnlocked = false;

private:
	bool bHasSavedData = false;
};
