// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 526: Ashen Environmental Weather Atmosphere Subsystem

#include "AshenEnvironmentalWeatherAtmosphereSubsystem.h"

void UAshenEnvironmentalWeatherAtmosphereSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenEnvironmentalWeatherAtmosphereSubsystem: Initialized — Environmental Weather Engine ONLINE."));
}

void UAshenEnvironmentalWeatherAtmosphereSubsystem::ModulateWeatherForCorruption(float RegionalCorruptionPercent)
{
	const float Normalized = FMath::Clamp(RegionalCorruptionPercent / 100.0f, 0.0f, 1.0f);
	const float StormDensity = Normalized * 100.0f;
	const float WindVelocity = 200.0f + (Normalized * 1200.0f); // 200u -> 1400u wind shear

	OnWeatherModulated.Broadcast(StormDensity, WindVelocity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenEnvironmentalWeatherAtmosphereSubsystem: WEATHER ATMOSPHERE MODULATED -> Corruption %.1f%% (Storm Density: %.1f%% | Wind Velocity: %.0fu/s)."),
		RegionalCorruptionPercent, StormDensity, WindVelocity);
}
