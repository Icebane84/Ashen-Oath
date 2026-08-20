// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenBrotherMalakorDialogueAdapter.h"

UAshenBrotherMalakorDialogueAdapter::UAshenBrotherMalakorDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenBrotherMalakorDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenBrotherMalakorDialogueAdapter::TriggerInquisitionCondemnation(uint8 PhaseIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenBrotherMalakorDialogueAdapter: Brother Malakor Phase %d dialogue ('Your sundered oaths cannot cleanse your soul, Kaelen!')"), PhaseIndex);
}
