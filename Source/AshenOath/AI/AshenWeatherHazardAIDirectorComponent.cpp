// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenWeatherHazardAIDirectorComponent.h"

UAshenWeatherHazardAIDirectorComponent::UAshenWeatherHazardAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWeatherHazardAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenWeatherHazardAIDirectorComponent::CalculateEnemyAggressionMultiplier(EWeatherState Weather) const
{
	float Aggression = 1.0f;
	switch (Weather)
	{
	case EWeatherState::PsychicStorm:
		Aggression = 1.45f; // Frenzied monsters
		break;
	case EWeatherState::VoidMiasma:
		Aggression = 1.25f; // Corrupted hunters
		break;
	case EWeatherState::AshBlizzard:
		Aggression = 0.85f; // Sluggish / seeking shelter
		break;
	case EWeatherState::ClearEmber:
	default:
		Aggression = 1.0f;
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherHazardAIDirectorComponent: Enemy Aggression Multiplier -> %.2fx for Weather %d."),
		Aggression, static_cast<int32>(Weather));

	return Aggression;
}
