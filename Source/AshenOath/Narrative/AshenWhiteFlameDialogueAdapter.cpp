// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenWhiteFlameDialogueAdapter.h"

UAshenWhiteFlameDialogueAdapter::UAshenWhiteFlameDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWhiteFlameDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenWhiteFlameDialogueAdapter::TriggerCatharsisDialogue()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenWhiteFlameDialogueAdapter: Kaelen & Serafina (In Unison): \"The flame does not burn us. We are the dawn!\""));
}
