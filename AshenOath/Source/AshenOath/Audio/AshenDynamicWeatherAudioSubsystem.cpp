// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 253: Ashen Dynamic Weather Audio Subsystem

#include "AshenDynamicWeatherAudioSubsystem.h"

void UAshenDynamicWeatherAudioSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentWindVolume = 0.2f;
	ActiveState = EAshenWeatherState::ClearCalm;
	UE_LOG(LogTemp, Log, TEXT("UAshenDynamicWeatherAudioSubsystem: Initialized — Weather Audio System active."));
}

void UAshenDynamicWeatherAudioSubsystem::UpdateWeatherAudio(EAshenWeatherState WeatherState)
{
	ActiveState = WeatherState;

	switch (WeatherState)
	{
	case EAshenWeatherState::ClearCalm:
		CurrentWindVolume = 0.2f;
		break;
	case EAshenWeatherState::LightFlurry:
		CurrentWindVolume = 0.5f;
		break;
	case EAshenWeatherState::HeavyBlizzard:
		CurrentWindVolume = 0.95f;
		break;
	case EAshenWeatherState::MindscapeStorm:
		CurrentWindVolume = 1.0f;
		break;
	default:
		CurrentWindVolume = 0.2f;
		break;
	}

	OnWeatherAudioUpdated.Broadcast(ActiveState, CurrentWindVolume);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDynamicWeatherAudioSubsystem: Weather audio updated to state %d — Wind Volume: %.2f."),
		(int32)ActiveState, CurrentWindVolume);
}
