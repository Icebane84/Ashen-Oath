// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Core/AshenShadowSeepageSaveGameAdapter.h"

UAshenShadowSeepageSaveGameAdapter::UAshenShadowSeepageSaveGameAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenShadowSeepageSaveGameAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenShadowSeepageSaveGameAdapter::SaveSeepageStatistics(float PeakCorruptionReached, float TotalUnchainedTime)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenShadowSeepageSaveGameAdapter: Saved Seepage Statistics (Peak Corruption: %.2f, Unchained Time: %.1fs) to SaveGame."),
		PeakCorruptionReached, TotalUnchainedTime);
	return true;
}
