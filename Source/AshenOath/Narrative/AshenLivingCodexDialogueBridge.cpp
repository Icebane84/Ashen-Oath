// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenLivingCodexDialogueBridge.h"

UAshenLivingCodexDialogueBridge::UAshenLivingCodexDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLivingCodexDialogueBridge::BeginPlay() { Super::BeginPlay(); }

bool UAshenLivingCodexDialogueBridge::IsDialogueNodeUnlockedByCodex(FName RequiredCodexID, bool bCodexUnlocked, bool bCodexRead)
{
	const bool bUnlocked = bCodexUnlocked && bCodexRead;
	UE_LOG(LogTemp, Log, TEXT("UAshenLivingCodexDialogueBridge: Dialogue Node for Codex '%s' unlocked: %s."),
		*RequiredCodexID.ToString(), bUnlocked ? TEXT("TRUE") : TEXT("FALSE"));
	return bUnlocked;
}
