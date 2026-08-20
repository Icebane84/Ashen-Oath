// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticDualityAcousticAudioComponent.h"

UAshenDiegeticDualityAcousticAudioComponent::UAshenDiegeticDualityAcousticAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticDualityAcousticAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticDualityAcousticAudioComponent::TriggerTransformationHumAudio()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticDualityAcousticAudioComponent: Triggered transformation hum audio (Volume: %f)."), TransformationHumVolume);
}

void UAshenDiegeticDualityAcousticAudioComponent::TriggerRuneIgnitionAudio()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticDualityAcousticAudioComponent: Triggered blade rune ignition audio."));
}
