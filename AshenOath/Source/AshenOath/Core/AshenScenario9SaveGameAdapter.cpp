// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenScenario9SaveGameAdapter.h"

UAshenScenario9SaveGameAdapter::UAshenScenario9SaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedGravityScale = 0.35f;
	SavedHighestAltitudeUU = 8500.0f;
	SavedBridgesActivated = 0;
	SavedAutomatonsCrushed = 0;
}

void UAshenScenario9SaveGameAdapter::PackageScenario9State(
	float FinalGravityScale,
	float HighestAltitudeUU,
	int32 BridgesActivated,
	int32 AutomatonsCrushed)
{
	SavedGravityScale = FinalGravityScale;
	SavedHighestAltitudeUU = HighestAltitudeUU;
	SavedBridgesActivated = BridgesActivated;
	SavedAutomatonsCrushed = AutomatonsCrushed;
	bHasSavedData = true;
}

bool UAshenScenario9SaveGameAdapter::RestoreScenario9State(
	float& OutGravityScale,
	float& OutAltitudeUU,
	int32& OutBridges,
	int32& OutAutomatons)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutGravityScale = SavedGravityScale;
	OutAltitudeUU = SavedHighestAltitudeUU;
	OutBridges = SavedBridgesActivated;
	OutAutomatons = SavedAutomatonsCrushed;
	return true;
}
