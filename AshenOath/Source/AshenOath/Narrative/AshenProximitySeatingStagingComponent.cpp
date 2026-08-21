// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenProximitySeatingStagingComponent.h"

UAshenProximitySeatingStagingComponent::UAshenProximitySeatingStagingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

ECompanionHearthSeating UAshenProximitySeatingStagingComponent::CalculateSeating(
	float Trust,
	float Dysregulation) const
{
	if (Dysregulation >= 0.70f || Trust < 0.35f)
	{
		return ECompanionHearthSeating::GuardedStandoff;
	}

	if (Trust >= 0.65f && Dysregulation < 0.40f)
	{
		return ECompanionHearthSeating::IntimateProximity;
	}

	return ECompanionHearthSeating::StandardFireside;
}

float UAshenProximitySeatingStagingComponent::GetSeatingDistanceUU(ECompanionHearthSeating Seating) const
{
	switch (Seating)
	{
	case ECompanionHearthSeating::IntimateProximity:
		return 250.0f;
	case ECompanionHearthSeating::StandardFireside:
		return 450.0f;
	case ECompanionHearthSeating::GuardedStandoff:
		return 800.0f;
	default:
		return 450.0f;
	}
}
