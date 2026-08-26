// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenWeatherShelterDirectorComponent.h"

UAshenWeatherShelterDirectorComponent::UAshenWeatherShelterDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenWeatherShelterDirectorComponent::EvaluateHazardMitigation(EWeatherShelterType ShelterType) const
{
	switch (ShelterType)
	{
	case EWeatherShelterType::HearthSanctuary:
		return 1.00f; // 100% total immunity
	case EWeatherShelterType::CavernOverhang:
		return 0.75f; // 75% protection
	case EWeatherShelterType::ExposedWilds:
	default:
		return 0.00f; // 0% protection
	}
}
