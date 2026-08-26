// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenWeatherNarrativeBridge.h"

UAshenWeatherNarrativeBridge::UAshenWeatherNarrativeBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenWeatherNarrativeBridge::FormatWeatherBark(
	EWeatherHazardState State,
	EWeatherShelterType Shelter) const
{
	if (Shelter == EWeatherShelterType::HearthSanctuary)
	{
		return FText::FromString(TEXT("[Serafina]: 'The hearth flame keeps the storm outside. We are safe here.'"));
	}
	else if (Shelter == EWeatherShelterType::CavernOverhang)
	{
		return FText::FromString(TEXT("[Garrett]: 'Stay under the stone. It'll keep the worst of the rain off our plates.'"));
	}

	switch (State)
	{
	case EWeatherHazardState::BlizzardWhiteout:
		return FText::FromString(TEXT("[Kaelen]: 'Frost is locking my joints. Keep moving or freeze!'"));
	case EWeatherHazardState::VolcanicAshStorm:
		return FText::FromString(TEXT("[Garrett]: 'Cover your mouth—this ash will choke your lungs before the beasts find you.'"));
	case EWeatherHazardState::AcidRainCorrosion:
		return FText::FromString(TEXT("[Serafina]: 'The rain is burning through our cloaks! Find cover!'"));
	case EWeatherHazardState::LightningSurge:
		return FText::FromString(TEXT("[Garrett]: 'Ground's ionizing! When the air tastes like copper, DODGE!'"));
	case EWeatherHazardState::ClearTemperate:
	default:
		return FText::FromString(TEXT("[Kaelen]: 'Winds are calm for now. Make good time.'"));
	}
}
