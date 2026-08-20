// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenCombatStanceDialogueAdapter.h"

UAshenCombatStanceDialogueAdapter::UAshenCombatStanceDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCombatStanceDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCombatStanceDialogueAdapter::TriggerStanceCombatBark(FName CompanionID, ECombatStance Stance, bool bFlankHit)
{
	FString Bark = TEXT("Hold the line!");
	if (bFlankHit)
	{
		Bark = TEXT("Right in the spine! Press the advantage!");
	}
	else if (Stance == ECombatStance::Berserk)
	{
		Bark = TEXT("Watch your guard, Kaelen! You're completely open!");
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenCombatStanceDialogueAdapter: %s: \"%s\" (Stance: %d)"),
		*CompanionID.ToString(), *Bark, static_cast<int32>(Stance));
}
