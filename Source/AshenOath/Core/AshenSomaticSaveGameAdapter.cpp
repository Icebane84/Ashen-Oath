// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenSomaticSaveGameAdapter.h"

UAshenSomaticSaveGameAdapter::UAshenSomaticSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSerializedData = false;
}

void UAshenSomaticSaveGameAdapter::PackageSomaticState(
	const FCanonicalSoulStateVector& SoulState,
	const FCanonicalRelationalMatrix& RelationalState,
	const TArray<FMemoryImprintPayload>& UncompiledImprints)
{
	SavedSoulState = SoulState;
	SavedRelationalState = RelationalState;
	SavedUncompiledImprints = UncompiledImprints;
	bHasSerializedData = true;
}

bool UAshenSomaticSaveGameAdapter::RestoreSomaticState(
	FCanonicalSoulStateVector& OutSoulState,
	FCanonicalRelationalMatrix& OutRelationalState,
	TArray<FMemoryImprintPayload>& OutUncompiledImprints)
{
	if (!bHasSerializedData)
	{
		return false;
	}

	OutSoulState = SavedSoulState;
	OutRelationalState = SavedRelationalState;
	OutUncompiledImprints = SavedUncompiledImprints;
	return true;
}
