// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenForensicMindscapeNarrativeBridge.h"

UAshenForensicMindscapeNarrativeBridge::UAshenForensicMindscapeNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenForensicMindscapeNarrativeBridge::FormatInvestigationBark(
	EMemoryReconstructionState State,
	EForensicClueCategory Category) const
{
	if (State == EMemoryReconstructionState::ReconstructedTruth)
	{
		return FText::FromString(TEXT("[Serafina]: 'The physical wounds don't lie. My Order's scriptures were forged to conceal this slaughter.'"));
	}

	switch (Category)
	{
	case EForensicClueCategory::PhysicalAutopsyEvidence:
		return FText::FromString(TEXT("[Garrett]: 'Look at that bone fracture. No beast did that—that's military steel.'"));
	case EForensicClueCategory::BotanicalChemicalSample:
		return FText::FromString(TEXT("[Garrett]: 'Vitriol acid residue in the marrow. Someone was dissolving the evidence.'"));
	case EForensicClueCategory::HistoricalRunicInscription:
		return FText::FromString(TEXT("[Serafina]: 'These runes predate the Sundering by two centuries.'"));
	default:
		return FText::FromString(TEXT("[Garrett]: 'Pin it to the board, Kaelen. Let us see how it fits.'"));
	}
}
