// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenMemoryFragmentCollectorComponent.h"

UAshenMemoryFragmentCollectorComponent::UAshenMemoryFragmentCollectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryFragmentCollectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenMemoryFragmentCollectorComponent::CollectMemoryFragment(FName FragmentID)
{
	TotalReclaimedFragments++;
	if (OnFragmentCollected.IsBound())
	{
		OnFragmentCollected.Broadcast(TotalReclaimedFragments);
	}
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryFragmentCollectorComponent: Fragment '%s' collected! Total Reclaimed: %d"),
		*FragmentID.ToString(), TotalReclaimedFragments);
}
