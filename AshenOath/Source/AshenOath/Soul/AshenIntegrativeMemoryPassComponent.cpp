// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 617: Ashen Integrative Memory Pass Component

#include "AshenIntegrativeMemoryPassComponent.h"

UAshenIntegrativeMemoryPassComponent::UAshenIntegrativeMemoryPassComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalMemoriesIntegrated = 0;
}

void UAshenIntegrativeMemoryPassComponent::ExecuteIntegrativePass(FName MemoryID, FName LensTag)
{
	if (MemoryID.IsNone()) return;

	TotalMemoriesIntegrated++;
	OnIntegrativeCompleted.Broadcast(MemoryID, LensTag);

	UE_LOG(LogTemp, Warning, TEXT("UAshenIntegrativeMemoryPassComponent: INTEGRATIVE PASS EXECUTED -> Memory '%s' | Lens: '%s' (Total Integrated: %d)."),
		*MemoryID.ToString(), *LensTag.ToString(), TotalMemoriesIntegrated);
}
