// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenMemoryBattleDialogueAdapter.h"

UAshenMemoryBattleDialogueAdapter::UAshenMemoryBattleDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryBattleDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenMemoryBattleDialogueAdapter::TriggerMemoryDialogue(FName EchoID, bool bVictory, FName SpeakerID)
{
	FString Callout = bVictory ?
		TEXT("The memory is integrated. Its hold over you is broken.") :
		TEXT("Do not let the past pull you into the dark, Kaelen!");

	UE_LOG(LogTemp, Warning, TEXT("UAshenMemoryBattleDialogueAdapter: %s: \"%s\" (Echo: %s)"),
		*SpeakerID.ToString(), *Callout, *EchoID.ToString());
}
