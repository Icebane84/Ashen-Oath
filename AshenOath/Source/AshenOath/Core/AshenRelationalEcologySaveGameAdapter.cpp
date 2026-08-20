// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Core/AshenRelationalEcologySaveGameAdapter.h"

UAshenRelationalEcologySaveGameAdapter::UAshenRelationalEcologySaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	bHasSerializedData = false;
}

void UAshenRelationalEcologySaveGameAdapter::PackageEcologyState(
	const FAshenRepairMatrix& GarrettMatrix,
	const FAshenRepairMatrix& SerafinaMatrix,
	const TArray<FAshenMultiAuthorMarginEntry>& Entries)
{
	SavedGarrettMatrix = GarrettMatrix;
	SavedSerafinaMatrix = SerafinaMatrix;
	SavedEntries = Entries;
	bHasSerializedData = true;
}

bool UAshenRelationalEcologySaveGameAdapter::RestoreEcologyState(
	FAshenRepairMatrix& OutGarrettMatrix,
	FAshenRepairMatrix& OutSerafinaMatrix,
	TArray<FAshenMultiAuthorMarginEntry>& OutEntries)
{
	if (!bHasSerializedData)
	{
		return false;
	}

	OutGarrettMatrix = SavedGarrettMatrix;
	OutSerafinaMatrix = SavedSerafinaMatrix;
	OutEntries = SavedEntries;
	return true;
}
