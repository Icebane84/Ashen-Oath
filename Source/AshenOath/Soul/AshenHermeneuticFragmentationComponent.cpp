// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 618: Ashen Hermeneutic Fragmentation Component

#include "AshenHermeneuticFragmentationComponent.h"

UAshenHermeneuticFragmentationComponent::UAshenHermeneuticFragmentationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalErosionAccumulated = 0.0f;
}

void UAshenHermeneuticFragmentationComponent::ExecuteFragmentationPass(FName MemoryID, float ErosionAmount)
{
	if (MemoryID.IsNone()) return;

	TotalErosionAccumulated += ErosionAmount;
	OnFragmentationExecuted.Broadcast(MemoryID, ErosionAmount);

	UE_LOG(LogTemp, Warning, TEXT("UAshenHermeneuticFragmentationComponent: FRAGMENTATION PASS EXECUTED -> Memory '%s' | Erosion: +%.1f (Total: %.1f)."),
		*MemoryID.ToString(), ErosionAmount, TotalErosionAccumulated);
}
