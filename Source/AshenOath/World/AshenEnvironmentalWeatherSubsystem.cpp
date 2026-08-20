// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenEnvironmentalWeatherSubsystem.h"

void UAshenEnvironmentalWeatherSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentWeatherState = EAshenWeatherState::ClearCalm;
	CurrentWindIntensity = 0.0f;
	UE_LOG(LogTemp, Warning, TEXT("UAshenEnvironmentalWeatherSubsystem: Weather Subsystem initialized (ClearCalm)."));
}

void UAshenEnvironmentalWeatherSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UAshenEnvironmentalWeatherSubsystem::SetWeatherState(EAshenWeatherState NewState)
{
	CurrentWeatherState = NewState;

	switch (NewState)
	{
	case EAshenWeatherState::ClearCalm:
		CurrentWindIntensity = 0.1f;
		break;
	case EAshenWeatherState::LightFlurry:
		CurrentWindIntensity = 0.4f;
		break;
	case EAshenWeatherState::HeavyBlizzard:
		CurrentWindIntensity = 0.85f;
		break;
	case EAshenWeatherState::MindscapeStorm:
		CurrentWindIntensity = 1.0f;
		break;
	}

	OnWeatherStateChanged.Broadcast(CurrentWeatherState, CurrentWindIntensity);
	UE_LOG(LogTemp, Warning, TEXT("UAshenEnvironmentalWeatherSubsystem: Weather updated to State %d (Wind: %.2f)."),
		(int32)CurrentWeatherState, CurrentWindIntensity);
}
