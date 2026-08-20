// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 426: Ashen Dynamic Weather VFX Subsystem

#include "AshenDynamicWeatherVFXSubsystem.h"

void UAshenDynamicWeatherVFXSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenDynamicWeatherVFXSubsystem: Initialized — Weather Volumetric VFX Engine ONLINE."));
}

void UAshenDynamicWeatherVFXSubsystem::ModulateVFXForWeatherState(EAshenWeatherState WeatherState)
{
	const float FogMult = (WeatherState == EAshenWeatherState::HeavyBlizzard) ? 3.5f : 1.0f;
	OnWeatherVFXUpdated.Broadcast(WeatherState, FogMult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDynamicWeatherVFXSubsystem: WEATHER VFX MODULATED -> State %d (Volumetric Fog Multiplier: %.2fx)."),
		(int32)WeatherState, FogMult);
}
