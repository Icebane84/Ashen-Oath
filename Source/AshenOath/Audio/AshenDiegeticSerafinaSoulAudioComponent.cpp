// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticSerafinaSoulAudioComponent.h"

UAshenDiegeticSerafinaSoulAudioComponent::UAshenDiegeticSerafinaSoulAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticSerafinaSoulAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticSerafinaSoulAudioComponent::PlayTransferenceChoirHum()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticSerafinaSoulAudioComponent: Ethereal choir hum and soul tether chimes active."));
}

void UAshenDiegeticSerafinaSoulAudioComponent::PlayBurnoutHeartbeatPulse(float BurnoutLevel)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticSerafinaSoulAudioComponent: Heartbeat quickening audio at Burnout %.1f/100.0"), BurnoutLevel);
}
