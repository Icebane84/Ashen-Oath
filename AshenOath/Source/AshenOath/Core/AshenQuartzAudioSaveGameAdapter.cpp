// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenQuartzAudioSaveGameAdapter.h"

UAshenQuartzAudioSaveGameAdapter::UAshenQuartzAudioSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedBPM = 115.0f;
	bSavedVocalsUnlocked = true;
	SavedTotalFlowStates = 0;
}

void UAshenQuartzAudioSaveGameAdapter::PackageAudioPreferences(
	float MasterBPM,
	bool bVocalTracksUnlocked,
	int32 TotalFlowStatesAchieved)
{
	SavedBPM = MasterBPM;
	bSavedVocalsUnlocked = bVocalTracksUnlocked;
	SavedTotalFlowStates = TotalFlowStatesAchieved;
	bHasSavedData = true;
}

bool UAshenQuartzAudioSaveGameAdapter::RestoreAudioPreferences(
	float& OutMasterBPM,
	bool& OutVocalTracksUnlocked,
	int32& OutTotalFlowStates)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutMasterBPM = SavedBPM;
	OutVocalTracksUnlocked = bSavedVocalsUnlocked;
	OutTotalFlowStates = SavedTotalFlowStates;
	return true;
}
