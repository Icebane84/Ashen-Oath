// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenDualSenseSaveGameAdapter.generated.h"

/**
 * UAshenDualSenseSaveGameAdapter
 * 
 * Serializes and restores player haptic calibration preferences and speaker volume.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualSenseSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDualSenseSaveGameAdapter();

	/** Packages haptic settings for save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	void PackageHapticSettings(float TriggerIntensity, float SpeakerVolume, bool bDisableHardLockouts);

	/** Restores haptic settings from save archive */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Core|SaveGame")
	bool RestoreHapticSettings(float& OutTriggerIntensity, float& OutSpeakerVolume, bool& OutDisableHardLockouts);

	UFUNCTION(BlueprintPure, Category = "Ashen|Core|SaveGame")
	bool HasSavedData() const { return bHasSavedData; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedTriggerIntensity = 1.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	float SavedSpeakerVolume = 1.0f;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Core|SaveGame")
	bool bSavedDisableHardLockouts = false;

private:
	bool bHasSavedData = false;
};
