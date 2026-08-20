// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 569: Ashen Weather Audio Modulation Subsystem

#include "AshenWeatherAudioModulationSubsystem.h"

void UAshenWeatherAudioModulationSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherAudioModulationSubsystem: Initialized — Weather Audio Engine ONLINE."));
}

void UAshenWeatherAudioModulationSubsystem::ModulateWeatherAudio(float StormDensityPercent)
{
	const float VolumeMult = FMath::Clamp(StormDensityPercent / 100.0f, 0.2f, 1.5f);
	const float Cutoff = FMath::Lerp(20000.0f, 3500.0f, StormDensityPercent / 100.0f);

	OnWeatherAudioModulated.Broadcast(VolumeMult, Cutoff);

	UE_LOG(LogTemp, Log, TEXT("UAshenWeatherAudioModulationSubsystem: WEATHER AUDIO MODULATED -> Vol Mult: %.2fx | LowPass Cutoff: %.0fHz."),
		VolumeMult, Cutoff);
}
