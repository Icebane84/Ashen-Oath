// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenTripartiteSaveGameAdapter.h"

UAshenTripartiteSaveGameAdapter::UAshenTripartiteSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedTotalFinishers = 0;
	SavedUnbrokenStreaks = 0;
	SavedCatharsisScore = 0.0f;
	SavedAttunementScore = 0.50f;
	SavedMode = ETripartiteBehaviorMode::CombatEngagement;
	bSavedSilenceMaintained = true;
}

void UAshenTripartiteSaveGameAdapter::PackageTripartiteData(
	int32 TotalFinishers,
	int32 UnbrokenStreaks,
	float CatharsisScore)
{
	SavedTotalFinishers = TotalFinishers;
	SavedUnbrokenStreaks = UnbrokenStreaks;
	SavedCatharsisScore = CatharsisScore;
	bHasSavedData = true;
}

bool UAshenTripartiteSaveGameAdapter::RestoreTripartiteData(
	int32& OutFinishers,
	int32& OutStreaks,
	float& OutCatharsis)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutFinishers = SavedTotalFinishers;
	OutStreaks = SavedUnbrokenStreaks;
	OutCatharsis = SavedCatharsisScore;
	return true;
}

void UAshenTripartiteSaveGameAdapter::PackageTripartiteState(
	float AttunementScore,
	ETripartiteBehaviorMode Mode,
	bool bSilenceMaintained)
{
	SavedAttunementScore = AttunementScore;
	SavedMode = Mode;
	bSavedSilenceMaintained = bSilenceMaintained;
	bHasSavedData = true;
}

bool UAshenTripartiteSaveGameAdapter::RestoreTripartiteState(
	float& OutAttunementScore,
	ETripartiteBehaviorMode& OutMode,
	bool& OutSilenceMaintained)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutAttunementScore = SavedAttunementScore;
	OutMode = SavedMode;
	OutSilenceMaintained = bSavedSilenceMaintained;
	return true;
}
