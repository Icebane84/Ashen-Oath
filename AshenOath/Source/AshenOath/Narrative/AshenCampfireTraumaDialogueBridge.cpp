// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenCampfireTraumaDialogueBridge.h"

UAshenCampfireTraumaDialogueBridge::UAshenCampfireTraumaDialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenCampfireTraumaDialogueBridge::FormatSeatingDialogue(
	const FString& BasePrompt,
	FName CompanionName,
	ECompanionHearthSeating Seating) const
{
	FString ContextStr;
	switch (Seating)
	{
	case ECompanionHearthSeating::IntimateProximity:
		ContextStr = TEXT("[Fireside Warmth: Sitting close by the embers, sharing quiet comfort.]");
		break;
	case ECompanionHearthSeating::GuardedStandoff:
		ContextStr = TEXT("[Guarded Standoff: Sitting at the edge of the shadows, watching the perimeter.]");
		break;
	default:
		ContextStr = TEXT("[Fireside: Resting quietly across the hearth.]");
		break;
	}

	const FString Formatted = FString::Printf(TEXT("%s\n%s"), *BasePrompt, *ContextStr);
	return FText::FromString(Formatted);
}
