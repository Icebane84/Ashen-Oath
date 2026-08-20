// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenBoundaryRefusalEvaluatorComponent.h"

UAshenBoundaryRefusalEvaluatorComponent::UAshenBoundaryRefusalEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

ECompanionBoundaryState UAshenBoundaryRefusalEvaluatorComponent::EvaluateBoundary(
	FName CompanionName,
	float CompanionTrust,
	float KaelenDysregulation,
	bool bIsSuicidalCharge) const
{
	// If Kaelen is in full dysregulation / suicidal charge, high trust refuses to follow into self-destruction
	if (bIsSuicidalCharge && KaelenDysregulation >= 0.75f && CompanionTrust >= 0.70f)
	{
		return ECompanionBoundaryState::BoundaryRefusal;
	}

	if (bIsSuicidalCharge && CompanionTrust < 0.50f)
	{
		return ECompanionBoundaryState::HesitantStandoff;
	}

	return ECompanionBoundaryState::AlignedFollow;
}
