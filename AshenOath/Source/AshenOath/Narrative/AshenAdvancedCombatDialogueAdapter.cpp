// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenAdvancedCombatDialogueAdapter.h"

UAshenAdvancedCombatDialogueAdapter::UAshenAdvancedCombatDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAdvancedCombatDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenAdvancedCombatDialogueAdapter::TriggerCombatReactionDialogue(FName CompanionID, FString CombatEventType)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenAdvancedCombatDialogueAdapter: %s dialogue triggered for event '%s' ('Flawless deflection, Kaelen!')"),
		*CompanionID.ToString(), *CombatEventType);
}
