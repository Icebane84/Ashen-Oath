// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenScenario8DialogueBridge.h"

UAshenScenario8DialogueBridge::UAshenScenario8DialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenScenario8DialogueBridge::FormatAbyssDialogueBark(
	ELightEnvironmentState LightState,
	EEcholocationPulseType Pulse) const
{
	if (Pulse == EEcholocationPulseType::RadiantFlarePulse)
	{
		return FText::FromString(TEXT("[Serafina]: 'Behold the White Flame! The abyss cannot conceal them now!'"));
	}

	if (Pulse == EEcholocationPulseType::GroundSlamSonar)
	{
		return FText::FromString(TEXT("[Garrett]: 'Echo return received! Three lurkers clinging to the ceiling ahead!'"));
	}

	if (LightState == ELightEnvironmentState::PitchBlackDarkness)
	{
		return FText::FromString(TEXT("[Garrett]: 'Torch is out... stay back-to-back, listen for their breathing!'"));
	}

	if (LightState == ELightEnvironmentState::GloomPerimeter)
	{
		return FText::FromString(TEXT("[Serafina]: 'Our resin is dwindling. The shadows are pressing in.'"));
	}

	return FText::FromString(TEXT("[Garrett]: 'Watch the chasm edges. The floor drops off without warning.'"));
}
