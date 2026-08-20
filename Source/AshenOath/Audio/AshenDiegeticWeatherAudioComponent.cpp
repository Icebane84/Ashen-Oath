// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticWeatherAudioComponent.h"

UAshenDiegeticWeatherAudioComponent::UAshenDiegeticWeatherAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticWeatherAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticWeatherAudioComponent::UpdateWeatherAudio(EWeatherState Weather, float WindIntensity, float FilterIntegrity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticWeatherAudioComponent: Weather Audio updated -> Weather: %d, Wind: %.2f, Filter: %.1f%%"),
		static_cast<int32>(Weather), WindIntensity, FilterIntegrity * 100.0f);
}

void UAshenDiegeticWeatherAudioComponent::PlayLightningStrikeCue()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticWeatherAudioComponent: Played PSYCHIC STORM LIGHTNING STRIKE CUE."));
}
