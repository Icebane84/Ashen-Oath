// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenScenario4SaveGameAdapter.generated.h"

/**
 * UAshenScenario4SaveGameAdapter
 * 
 * Serializes and restores Scenario 4 completion state, discovered Cognitive Loci, and Sanity vectors.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenScenario4SaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenScenario4SaveGameAdapter();

	/** Packages Scenario 4 progress for save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageScenario4State(bool bWhisperwoodCleared, int32 CognitiveLociCount, float ResultingSanity);

	/** Restores Scenario 4 progress from save game file */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreScenario4State(bool& OutWhisperwoodCleared, int32& OutCognitiveLociCount, float& OutResultingSanity);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedWhisperwoodCleared = false;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedCognitiveLociCount = 0;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedResultingSanity = 1.0f;

private:
	bool bHasSavedData = false;
};
