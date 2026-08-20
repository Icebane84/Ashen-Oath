// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenWeatherMiasmaSubsystem.h"

void UAshenWeatherMiasmaSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	AtmosphereData.CurrentWeather = EWeatherState::ClearEmber;
	AtmosphereData.AtmosphericToxicity = 0.0f;
	AtmosphereData.WindVelocity = 100.0f;
	AtmosphereData.VisibilityRange = 5000.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherMiasmaSubsystem: Weather & Miasma Subsystem initialized (Default: ClearEmber)."));
}
void UAshenWeatherMiasmaSubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenWeatherMiasmaSubsystem::TransitionToWeather(EWeatherState NewWeather)
{
	if (AtmosphereData.CurrentWeather == NewWeather) return false;

	AtmosphereData.CurrentWeather = NewWeather;
	switch (NewWeather)
	{
	case EWeatherState::VoidMiasma:
		AtmosphereData.AtmosphericToxicity = 0.75f;
		AtmosphereData.VisibilityRange = 1500.0f;
		AtmosphereData.WindVelocity = 150.0f;
		break;
	case EWeatherState::AshBlizzard:
		AtmosphereData.AtmosphericToxicity = 0.35f;
		AtmosphereData.VisibilityRange = 1200.0f;
		AtmosphereData.WindVelocity = 600.0f;
		break;
	case EWeatherState::PsychicStorm:
		AtmosphereData.AtmosphericToxicity = 0.50f;
		AtmosphereData.VisibilityRange = 2500.0f;
		AtmosphereData.WindVelocity = 400.0f;
		break;
	case EWeatherState::ClearEmber:
	default:
		AtmosphereData.AtmosphericToxicity = 0.0f;
		AtmosphereData.VisibilityRange = 5000.0f;
		AtmosphereData.WindVelocity = 100.0f;
		break;
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenWeatherMiasmaSubsystem: Weather transitioned to %d (Toxicity: %.2f, Vis: %.1fuu, Wind: %.1fuu/s)."),
		static_cast<int32>(NewWeather), AtmosphereData.AtmosphericToxicity, AtmosphereData.VisibilityRange, AtmosphereData.WindVelocity);

	return true;
}
