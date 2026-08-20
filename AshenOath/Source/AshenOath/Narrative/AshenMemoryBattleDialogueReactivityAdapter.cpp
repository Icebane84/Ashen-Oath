// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenMemoryBattleDialogueReactivityAdapter.h"

UAshenMemoryBattleDialogueReactivityAdapter::UAshenMemoryBattleDialogueReactivityAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryBattleDialogueReactivityAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenMemoryBattleDialogueReactivityAdapter::UnlockVictoryDialogueBranch(FName MemoryID)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryBattleDialogueReactivityAdapter: Victory dialogue branch unlocked for memory '%s'"), *MemoryID.ToString());
	return true;
}
