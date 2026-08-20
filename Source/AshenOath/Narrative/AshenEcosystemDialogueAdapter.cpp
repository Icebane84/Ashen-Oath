// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenEcosystemDialogueAdapter.h"

UAshenEcosystemDialogueAdapter::UAshenEcosystemDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEcosystemDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenEcosystemDialogueAdapter::TriggerTargetSwapDialogue()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenEcosystemDialogueAdapter: Garrett: \"Swap on three! Kaelen, take the Shade! I've got the Bastion!\""));
}

void UAshenEcosystemDialogueAdapter::TriggerHarmonicArmorCrackDialogue()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenEcosystemDialogueAdapter: Serafina: \"The plates are vibrating—strike the fracture now, Kaelen!\""));
}
