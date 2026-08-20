// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenCompanionIntentSaveGameAdapter.h"

UAshenCompanionIntentSaveGameAdapter::UAshenCompanionIntentSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasData = false;
}

void UAshenCompanionIntentSaveGameAdapter::PackageIntentHistory(const TArray<FCompanionIntentEvaluationResult>& History)
{
	SavedHistory = History;
	bHasData = true;
}

bool UAshenCompanionIntentSaveGameAdapter::RestoreIntentHistory(TArray<FCompanionIntentEvaluationResult>& OutHistory)
{
	if (!bHasData)
	{
		return false;
	}

	OutHistory = SavedHistory;
	return true;
}
