// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenSeveranceNarrativeBridge.h"

UAshenSeveranceNarrativeBridge::UAshenSeveranceNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenSeveranceNarrativeBridge::FormatExecutionBark(
	ESeveranceSeverityTier Severity) const
{
	switch (Severity)
	{
	case ESeveranceSeverityTier::Decapitation:
		return FText::FromString(TEXT("[Garrett]: 'Clean neck cleave. That steel didn't hesitate for a heartbeat.'"));
	case ESeveranceSeverityTier::TotalBisection:
		return FText::FromString(TEXT("[Serafina]: 'May the Flame forgive the savagery of this sundering world.'"));
	case ESeveranceSeverityTier::MajorLimb:
		return FText::FromString(TEXT("[Garrett]: 'Weapon arm severed! He won't be holding a spear again.'"));
	case ESeveranceSeverityTier::MinorLimb:
	default:
		return FText::FromString(TEXT("[Garrett]: 'Keep swinging, Kaelen! Break their lines!'"));
	}
}
