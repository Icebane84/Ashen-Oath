// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenWaystationSaveGameAdapter.h"

UAshenWaystationSaveGameAdapter::UAshenWaystationSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedRunMode = EWaystationRunMode::RunA_ShadowHarvest;
	SavedDecision = EScoutCatalystDecision::HarvestResidualTaint;
	SavedSerafinaDistance = 1000.0f;
	SavedHesitationMS = 300.0f;
}

void UAshenWaystationSaveGameAdapter::PackageWaystationState(
	EWaystationRunMode Mode,
	EScoutCatalystDecision Decision,
	float SerafinaDist,
	float HesitationMS)
{
	SavedRunMode = Mode;
	SavedDecision = Decision;
	SavedSerafinaDistance = SerafinaDist;
	SavedHesitationMS = HesitationMS;
	bHasSavedData = true;
}

bool UAshenWaystationSaveGameAdapter::RestoreWaystationState(
	EWaystationRunMode& OutMode,
	EScoutCatalystDecision& OutDecision,
	float& OutSerafinaDist,
	float& OutHesitationMS)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutMode = SavedRunMode;
	OutDecision = SavedDecision;
	OutSerafinaDist = SavedSerafinaDistance;
	OutHesitationMS = SavedHesitationMS;
	return true;
}
