// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenCSESaveGameAdapter.h"

UAshenCSESaveGameAdapter::UAshenCSESaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSavedData = false;
	SavedDissonanceIndex = 0.15f;
	SavedTier = ECognitiveDissonanceTier::HarmonicConsensus;
	SavedResolvedCount = 0;
}

void UAshenCSESaveGameAdapter::PackageCSEState(
	float DissonanceIndex,
	ECognitiveDissonanceTier Tier,
	int32 ResolvedContractCount)
{
	SavedDissonanceIndex = DissonanceIndex;
	SavedTier = Tier;
	SavedResolvedCount = ResolvedContractCount;
	bHasSavedData = true;
}

bool UAshenCSESaveGameAdapter::RestoreCSEState(
	float& OutDissonanceIndex,
	ECognitiveDissonanceTier& OutTier,
	int32& OutResolvedContractCount)
{
	if (!bHasSavedData)
	{
		return false;
	}

	OutDissonanceIndex = SavedDissonanceIndex;
	OutTier = SavedTier;
	OutResolvedContractCount = SavedResolvedCount;
	return true;
}
