// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenScenario2SaveGameAdapter.generated.h"

/**
 * UAshenScenario2SaveGameAdapter
 * 
 * Serializes and restores Scenario 2 mission completion state, stealth score, and Garrett's tactical profile.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario2SaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario2SaveGameAdapter();

	/** Packages Scenario 2 progress for save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageScenario2State(bool bSilentEscape, int32 EnemiesFunneled, const FString& GarrettTacticalProfile);

	/** Restores Scenario 2 progress from save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreScenario2State(bool& OutSilentEscape, int32& OutEnemiesFunneled, FString& OutGarrettTacticalProfile);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedSilentEscape = false;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedEnemiesFunneled = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	FString SavedTacticalProfile = TEXT("Calculated_Pragmatic");

private:
	bool bHasSavedData = false;
};
