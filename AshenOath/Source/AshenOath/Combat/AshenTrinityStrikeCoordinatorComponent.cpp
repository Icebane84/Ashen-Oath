// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenTrinityStrikeCoordinatorComponent.h"

UAshenTrinityStrikeCoordinatorComponent::UAshenTrinityStrikeCoordinatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenTrinityStrikeCoordinatorComponent::EvaluateTrinityDamageMultiplier(ETrinityStrikeStep Step) const
{
	switch (Step)
	{
	case ETrinityStrikeStep::SerafinaPurgeBeam:
		return 3.50f; // 3.5x finisher
	case ETrinityStrikeStep::GarrettThreadLock:
		return 1.75f;
	case ETrinityStrikeStep::KaelenGuardBreak:
		return 1.25f;
	case ETrinityStrikeStep::None:
	default:
		return 1.00f;
	}
}

bool UAshenTrinityStrikeCoordinatorComponent::IsStepValid(
	ETrinityStrikeStep CurrentStep,
	ETrinityStrikeStep AttemptedStep) const
{
	switch (CurrentStep)
	{
	case ETrinityStrikeStep::None:
		return AttemptedStep == ETrinityStrikeStep::KaelenGuardBreak;
	case ETrinityStrikeStep::KaelenGuardBreak:
		return AttemptedStep == ETrinityStrikeStep::GarrettThreadLock;
	case ETrinityStrikeStep::GarrettThreadLock:
		return AttemptedStep == ETrinityStrikeStep::SerafinaPurgeBeam;
	case ETrinityStrikeStep::SerafinaPurgeBeam:
	default:
		return false;
	}
}
