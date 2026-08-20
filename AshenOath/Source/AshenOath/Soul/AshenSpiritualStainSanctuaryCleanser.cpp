// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 684: Ashen Spiritual Stain Sanctuary Cleanser

#include "AshenSpiritualStainSanctuaryCleanser.h"

void UAshenSpiritualStainSanctuaryCleanser::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalCleansesExecuted = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenSpiritualStainSanctuaryCleanser: Initialized — Spiritual Stain Sanctuary Cleanser ONLINE."));
}

bool UAshenSpiritualStainSanctuaryCleanser::CleanseStainAtSanctuary(float CurrentStainPercent, int32 AvailableSanctuaryResources)
{
	const int32 RequiredResources = 50; // 50 sanctuary resources per cleanse pass
	if (AvailableSanctuaryResources < RequiredResources || CurrentStainPercent <= 0.0f)
	{
		return false;
	}

	TotalCleansesExecuted++;
	const float CleanseAmount = 15.0f; // Cleanses 15% stain
	const float RemainingStain = FMath::Clamp(CurrentStainPercent - CleanseAmount, 0.0f, 100.0f);

	OnSanctuaryCleanseExecuted.Broadcast(RequiredResources, CleanseAmount, RemainingStain);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSpiritualStainSanctuaryCleanser: SANCTUARY CLEANSE EXECUTED -> Consumed: %d resources | Cleansed: %.1f%% | Remaining Stain: %.1f%%."),
		RequiredResources, CleanseAmount, RemainingStain);

	return true;
}
