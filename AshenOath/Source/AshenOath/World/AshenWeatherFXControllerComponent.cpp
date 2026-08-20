// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 189: Ashen Weather FX Controller Component

#include "AshenWeatherFXControllerComponent.h"

UAshenWeatherFXControllerComponent::UAshenWeatherFXControllerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentWeather = EAshenWeatherState::ClearCalm;
	CurrentIntensity = 0.0f;
}

void UAshenWeatherFXControllerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenWeatherFXControllerComponent::ApplyWeatherFX(EAshenWeatherState WeatherType, float Intensity)
{
	CurrentWeather = WeatherType;
	CurrentIntensity = FMath::Clamp(Intensity, 0.0f, 1.0f);

	OnWeatherFXUpdated.Broadcast(CurrentWeather, CurrentIntensity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenWeatherFXControllerComponent: Weather FX APPLIED — Type: %d, Intensity: %.1f%%."),
		(int32)CurrentWeather, CurrentIntensity * 100.0f);
}
