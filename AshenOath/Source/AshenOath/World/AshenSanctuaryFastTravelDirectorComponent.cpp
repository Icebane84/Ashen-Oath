// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenSanctuaryFastTravelDirectorComponent.h"

UAshenSanctuaryFastTravelDirectorComponent::UAshenSanctuaryFastTravelDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenSanctuaryFastTravelDirectorComponent::EvaluateFastTravelStaminaCost(float DistanceKm) const
{
	const float SafeDist = FMath::Clamp(DistanceKm, 0.5f, 20.0f);
	return SafeDist * 15.0f; // 15 stamina per km
}
