// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenBladeSanityNarrativeBridge.h"

UAshenBladeSanityNarrativeBridge::UAshenBladeSanityNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenBladeSanityNarrativeBridge::FormatConvergenceBark(
	ESanityDissonanceTier Tier,
	bool bFlowActive) const
{
	if (bFlowActive)
	{
		return FText::FromString(TEXT("[Serafina]: 'The White Flame sings through you—the shadows are banished!'"));
	}

	switch (Tier)
	{
	case ESanityDissonanceTier::DeliriumMadness:
		return FText::FromString(TEXT("[Garrett]: 'KAELEN! Look at me! Don't listen to the blade's voice!'"));
	case ESanityDissonanceTier::ParanoidStatic:
		return FText::FromString(TEXT("[Serafina]: 'The whispers are clouding your mind. Breathe and find the rhythm.'"));
	case ESanityDissonanceTier::AnxiousEchoes:
		return FText::FromString(TEXT("[Garrett]: 'Blade's getting hungry. Don't let it drink too deep.'"));
	case ESanityDissonanceTier::LucidHarmonic:
	default:
		return FText::FromString(TEXT("[Kaelen]: 'My thoughts are clear. The sword is disciplined.'"));
	}
}
