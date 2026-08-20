// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticMiasmaWhisperAudioComponent.h"

UAshenDiegeticMiasmaWhisperAudioComponent::UAshenDiegeticMiasmaWhisperAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticMiasmaWhisperAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticMiasmaWhisperAudioComponent::UpdateWhisperPitchModulation(float CorruptionLevel)
{
	WhisperSpatialIntensity = FMath::Clamp(CorruptionLevel / 100.0f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticMiasmaWhisperAudioComponent: Whisper spatial intensity updated to %f"), WhisperSpatialIntensity);
}
