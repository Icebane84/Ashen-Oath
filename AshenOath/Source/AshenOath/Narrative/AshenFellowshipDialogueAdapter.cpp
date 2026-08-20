// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenFellowshipDialogueAdapter.h"

UAshenFellowshipDialogueAdapter::UAshenFellowshipDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenFellowshipDialogueAdapter::ShouldHesitateBark(
	ERelationalRuptureState RuptureState,
	float TrustLevel) const
{
	if (RuptureState == ERelationalRuptureState::ActiveRupture || RuptureState == ERelationalRuptureState::DeepEstrangement)
	{
		return true;
	}
	return TrustLevel < 0.35f;
}

float UAshenFellowshipDialogueAdapter::GetCompanionGazeWeight(
	ERelationalRuptureState RuptureState,
	float TrustLevel) const
{
	if (RuptureState == ERelationalRuptureState::ActiveRupture)
	{
		return 0.20f; // Averted eyes / cold gaze
	}
	return FMath::Clamp(TrustLevel, 0.40f, 1.0f);
}
