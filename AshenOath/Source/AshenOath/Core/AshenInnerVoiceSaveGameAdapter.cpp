// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenInnerVoiceSaveGameAdapter.h"

UAshenInnerVoiceSaveGameAdapter::UAshenInnerVoiceSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasData = false;
}

void UAshenInnerVoiceSaveGameAdapter::PackageVoiceHistory(const TArray<FAshenInnerVoicePayload>& History)
{
	SavedVoiceHistory = History;
	bHasData = true;
}

bool UAshenInnerVoiceSaveGameAdapter::RestoreVoiceHistory(TArray<FAshenInnerVoicePayload>& OutHistory)
{
	if (!bHasData)
	{
		return false;
	}

	OutHistory = SavedVoiceHistory;
	return true;
}
