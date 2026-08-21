// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenDualSenseSaveGameAdapter.h"

UAshenDualSenseSaveGameAdapter::UAshenDualSenseSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
}

void UAshenDualSenseSaveGameAdapter::PackageHapticSettings(
	float TriggerIntensity,
	float SpeakerVolume,
	bool bDisableHardLockouts)
{
	SavedTriggerIntensity = TriggerIntensity;
	SavedSpeakerVolume = SpeakerVolume;
	bSavedDisableHardLockouts = bDisableHardLockouts;
	bHasSavedData = true;
}

bool UAshenDualSenseSaveGameAdapter::RestoreHapticSettings(
	float& OutTriggerIntensity,
	float& OutSpeakerVolume,
	bool& OutDisableHardLockouts)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutTriggerIntensity = SavedTriggerIntensity;
	OutSpeakerVolume = SavedSpeakerVolume;
	OutDisableHardLockouts = bSavedDisableHardLockouts;
	return true;
}
