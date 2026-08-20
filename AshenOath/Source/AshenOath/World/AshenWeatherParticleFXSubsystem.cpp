// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 571: Ashen Weather Particle FX Subsystem

#include "AshenWeatherParticleFXSubsystem.h"

void UAshenWeatherParticleFXSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherParticleFXSubsystem: Initialized — Weather Particle FX Engine ONLINE."));
}

void UAshenWeatherParticleFXSubsystem::SpawnWeatherParticleFX(FName WeatherTypeTag, float Density)
{
	CurrentActiveWeatherTag = WeatherTypeTag;
	OnWeatherParticleFXSpawned.Broadcast(WeatherTypeTag, Density);

	UE_LOG(LogTemp, Warning, TEXT("UAshenWeatherParticleFXSubsystem: WEATHER PARTICLE FX SPAWNED -> Tag: '%s' | Density: %.1f."),
		*WeatherTypeTag.ToString(), Density);
}
