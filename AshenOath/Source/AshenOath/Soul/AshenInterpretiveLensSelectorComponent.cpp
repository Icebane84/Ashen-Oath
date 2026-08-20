// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 627: Ashen Interpretive Lens Selector Component

#include "AshenInterpretiveLensSelectorComponent.h"

UAshenInterpretiveLensSelectorComponent::UAshenInterpretiveLensSelectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentActiveLens = EAshenInterpretiveLens::Grace;
}

void UAshenInterpretiveLensSelectorComponent::SelectLensForMemory(FName MemoryID, EAshenInterpretiveLens Lens)
{
	if (MemoryID.IsNone()) return;

	CurrentActiveLens = Lens;
	OnLensSelected.Broadcast(MemoryID, Lens);

	UE_LOG(LogTemp, Warning, TEXT("UAshenInterpretiveLensSelectorComponent: LENS SELECTED -> Memory '%s' | Lens: %s."),
		*MemoryID.ToString(), (Lens == EAshenInterpretiveLens::Grace) ? TEXT("GRACE") : TEXT("ACCOUNTABILITY"));
}
