// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCSENarrativeBridge.h"

UAshenCSENarrativeBridge::UAshenCSENarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenCSENarrativeBridge::FormatDissonanceBark(ECognitiveDissonanceTier Tier) const
{
	switch (Tier)
	{
	case ECognitiveDissonanceTier::PsychologicalFracture:
		return FText::FromString(TEXT("[Garrett]: 'We can't keep pretending we're fighting for the same thing, Kaelen!'"));
	case ECognitiveDissonanceTier::IdeologicalDivergence:
		return FText::FromString(TEXT("[Serafina]: 'Your methods border on heresy. We must seek the true light.'"));
	case ECognitiveDissonanceTier::PhilosophicalFriction:
		return FText::FromString(TEXT("[Garrett]: 'I disagree with your strategy, but I'll watch your back.'"));
	case ECognitiveDissonanceTier::HarmonicConsensus:
	default:
		return FText::FromString(TEXT("[Serafina]: 'Our spirits move as one flame. Strike without doubt!'"));
	}
}
