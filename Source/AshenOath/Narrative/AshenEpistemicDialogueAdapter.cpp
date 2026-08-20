// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenEpistemicDialogueAdapter.h"

UAshenEpistemicDialogueAdapter::UAshenEpistemicDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEpistemicDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenEpistemicDialogueAdapter::TriggerHistoricalEventBark(FName CompanionID, FName EncounterID, bool bWasSynarchy)
{
	if (bWasSynarchy)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenEpistemicDialogueAdapter: %s: \"I remember when we took down %s. We held the line together.\""),
			*CompanionID.ToString(), *EncounterID.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenEpistemicDialogueAdapter: %s: \"Don't rush in like you did at %s, Kaelen. We almost lost you.\""),
			*CompanionID.ToString(), *EncounterID.ToString());
	}
}
