// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenSanctuarySurvivalSaveGameAdapter.generated.h"

/**
 * UAshenSanctuarySurvivalSaveGameAdapter
 * 
 * Serializes active meal buffs, body temperature, unlocked sanctuary beacons, and recorded forensic journal entries.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuarySurvivalSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuarySurvivalSaveGameAdapter();

	/** Packages survival state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageSurvivalState(ECookedMealBuffType ActiveMeal, float MealDuration, int32 IgnitedBeaconsCount);

	/** Restores survival state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreSurvivalState(ECookedMealBuffType& OutMeal, float& OutDuration, int32& OutIgnitedCount);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	ECookedMealBuffType SavedMeal = ECookedMealBuffType::None;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedDuration = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	int32 SavedIgnitedCount = 0;

private:
	bool bHasSavedData = false;
};
