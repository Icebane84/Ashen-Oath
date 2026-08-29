// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenOathbringerStanceNarrativeBridge.h"

UAshenOathbringerStanceNarrativeBridge::UAshenOathbringerStanceNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenOathbringerStanceNarrativeBridge::FormatStanceBark(
	EOathbringerMartialStance Stance,
	bool bCleanFlowGlint) const
{
	if (bCleanFlowGlint)
	{
		return FText::FromString(TEXT("[Garrett]: 'Flawless transition, Kaelen! Press the momentum!'"));
	}

	switch (Stance)
	{
	case EOathbringerMartialStance::Mordhau_HalfSword:
		return FText::FromString(TEXT("[Serafina]: 'Crumble their armor! Strike with the pommel!'"));
	case EOathbringerMartialStance::Ochs_CrownGuard:
		return FText::FromString(TEXT("[Garrett]: 'Good bind! Riposte through their guard!'"));
	case EOathbringerMartialStance::Pflug_LowPlow:
		return FText::FromString(TEXT("[Serafina]: 'Pierce their line, quick and true!'"));
	case EOathbringerMartialStance::VomTag_HighWrath:
	default:
		return FText::FromString(TEXT("[Garrett]: 'Bring the hammer down! Split them open!'"));
	}
}
