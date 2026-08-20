// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenMemoryPalaceDialogueAdapter.h"

UAshenMemoryPalaceDialogueAdapter::UAshenMemoryPalaceDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenMemoryPalaceDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenMemoryPalaceDialogueAdapter::IsLoreDialogueUnlocked(FName LoreID, int32 UnsealedLocusCount)
{
	bool bUnlocked = false;
	if (LoreID == FName(TEXT("Lore.TheSunderingEvent")))
	{
		bUnlocked = UnsealedLocusCount >= 3;
	}
	else
	{
		bUnlocked = UnsealedLocusCount >= 1;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenMemoryPalaceDialogueAdapter: Lore Branch '%s' evaluated (Unlocked: %s, Unsealed Count: %d)."),
		*LoreID.ToString(), bUnlocked ? TEXT("TRUE") : TEXT("FALSE"), UnsealedLocusCount);

	return bUnlocked;
}
