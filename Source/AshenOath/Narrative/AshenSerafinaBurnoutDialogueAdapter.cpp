// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenSerafinaBurnoutDialogueAdapter.h"

UAshenSerafinaBurnoutDialogueAdapter::UAshenSerafinaBurnoutDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSerafinaBurnoutDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenSerafinaBurnoutDialogueAdapter::TriggerWearyDialogue(float BurnoutLevel)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaBurnoutDialogueAdapter: Serafina weary voice line triggered (Burnout: %.1f) ('I can still carry this, Kaelen...')"), BurnoutLevel);
}
