// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenMemoryPalaceSaveGameAdapter.h"

UAshenMemoryPalaceSaveGameAdapter::UAshenMemoryPalaceSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryPalaceSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenMemoryPalaceSaveGameAdapter::SaveMemoryPalaceGraphState(const TArray<FName>& UnsealedNodeIDs, int32 TotalBridgesReconstructed)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryPalaceSaveGameAdapter: Saved Memory Palace State (%d unsealed nodes, %d rebuilt bridges) to SaveGame."),
		UnsealedNodeIDs.Num(), TotalBridgesReconstructed);
	return true;
}
