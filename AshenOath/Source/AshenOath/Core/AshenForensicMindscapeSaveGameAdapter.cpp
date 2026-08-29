// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenForensicMindscapeSaveGameAdapter.h"

UAshenForensicMindscapeSaveGameAdapter::UAshenForensicMindscapeSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedDiscoveredCount = 0;
	SavedSolvedCount = 0;
	SavedSynthesisScore = 0.0f;
}

void UAshenForensicMindscapeSaveGameAdapter::PackageForensicState(
	int32 DiscoveredCount,
	int32 SolvedCount,
	float LastSynthesisScore)
{
	SavedDiscoveredCount = DiscoveredCount;
	SavedSolvedCount = SolvedCount;
	SavedSynthesisScore = LastSynthesisScore;
	bHasSavedData = true;
}

bool UAshenForensicMindscapeSaveGameAdapter::RestoreForensicState(
	int32& OutDiscoveredCount,
	int32& OutSolvedCount,
	float& OutSynthesisScore)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutDiscoveredCount = SavedDiscoveredCount;
	OutSolvedCount = SavedSolvedCount;
	OutSynthesisScore = SavedSynthesisScore;
	return true;
}
