// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenTraumaSaveGameAdapter.h"

UAshenTraumaSaveGameAdapter::UAshenTraumaSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTraumaSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenTraumaSaveGameAdapter::SaveTraumaMetrics(float PeakDebt, int32 UnchainedActivationsCount, int32 ForcedMindscapeCount)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenTraumaSaveGameAdapter: Saved Trauma Metrics (Peak Debt: %.1f%%, Unchained Count: %d, Mindscapes: %d) to SaveGame."),
		PeakDebt, UnchainedActivationsCount, ForcedMindscapeCount);
	return true;
}
