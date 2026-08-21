// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenScenario2DialogueBridge.h"

UAshenScenario2DialogueBridge::UAshenScenario2DialogueBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenScenario2DialogueBridge::FormatGarrettTacticalBark(EPathfindingDisruptionTier DisruptionTier) const
{
	switch (DisruptionTier)
	{
	case EPathfindingDisruptionTier::CircuitBreakerTripped:
		return FText::FromString(TEXT("[Garrett]: 'Their routing just collapsed. Funnel the panic right off the edge.'"));
	case EPathfindingDisruptionTier::DegradedRouting:
		return FText::FromString(TEXT("[Garrett]: 'Wire tension holding. They're breaking formation.'"));
	case EPathfindingDisruptionTier::NormalNavigation:
	default:
		return FText::FromString(TEXT("[Garrett]: 'Keep low. Traps set in the choke points.'"));
	}
}
