// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenLivingJournalDialogueAdapter.h"

UAshenLivingJournalDialogueAdapter::UAshenLivingJournalDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLivingJournalDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenLivingJournalDialogueAdapter::TriggerConstellationSectorDialogue(EConstellationNodeVisual SectorState)
{
	if (SectorState == EConstellationNodeVisual::GoldWhiteLeyConduit)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenLivingJournalDialogueAdapter: Kaelen: \"The ley-lines hold. We broke the nightmare here, together.\""));
	}
	else if (SectorState == EConstellationNodeVisual::ObsidianFracture)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenLivingJournalDialogueAdapter: Kaelen: \"The stone is scorched black. I can still feel the stain throbbing in my marrow.\""));
	}
}
