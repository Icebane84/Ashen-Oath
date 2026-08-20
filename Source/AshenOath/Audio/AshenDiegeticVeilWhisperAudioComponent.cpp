// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticVeilWhisperAudioComponent.h"

UAshenDiegeticVeilWhisperAudioComponent::UAshenDiegeticVeilWhisperAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticVeilWhisperAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticVeilWhisperAudioComponent::UpdateVeilWhisperFrequency(float PhaseShiftIntensity)
{
	VeilWhisperVolume = FMath::Clamp(PhaseShiftIntensity, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticVeilWhisperAudioComponent: Veil whisper volume updated to %f"), VeilWhisperVolume);
}
