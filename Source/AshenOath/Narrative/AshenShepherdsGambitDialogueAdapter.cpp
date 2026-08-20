// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenShepherdsGambitDialogueAdapter.h"

UAshenShepherdsGambitDialogueAdapter::UAshenShepherdsGambitDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenShepherdsGambitDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenShepherdsGambitDialogueAdapter::TriggerContainmentBark(EUnchainedHazardLevel HazardLevel)
{
	if (HazardLevel == EUnchainedHazardLevel::Catastrophic)
	{
		UE_LOG(LogTemp, Error, TEXT("UAshenShepherdsGambitDialogueAdapter: Garrett: \"Serafina, get back! He doesn't see us anymore!\""));
	}
	else if (HazardLevel == EUnchainedHazardLevel::Hazardous)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenShepherdsGambitDialogueAdapter: Serafina: \"Kaelen, hear my voice! Hold to the anchor!\""));
	}
}
