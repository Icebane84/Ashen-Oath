// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenCombatKinematicsSaveGameAdapter.generated.h"

/**
 * UAshenCombatKinematicsSaveGameAdapter
 * 
 * Serializes weight class configuration, posture mastery bonuses, and kinematics calibration parameters to SaveGame files.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatKinematicsSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCombatKinematicsSaveGameAdapter();

	/** Packages combat kinematics state for SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageKinematicsState(float CurrentWeightKg, float MaxEquipLoadKg, EAshenWeightClass WeightClass);

	/** Restores combat kinematics state from SaveGame */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreKinematicsState(float& OutCurrentWeightKg, float& OutMaxEquipLoadKg, EAshenWeightClass& OutWeightClass);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedCurrentWeightKg = 25.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedMaxEquipLoadKg = 50.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	EAshenWeightClass SavedWeightClass = EAshenWeightClass::MediumLoad;

private:
	bool bHasSavedData = false;
};
