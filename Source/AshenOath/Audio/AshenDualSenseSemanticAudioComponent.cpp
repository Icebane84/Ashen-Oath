// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenDualSenseSemanticAudioComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"

UAshenDualSenseSemanticAudioComponent::UAshenDualSenseSemanticAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	BaseWorldLowPassCutoffHz = 20000.0f;
	MaxParasiteDuckingCutoffHz = 400.0f;
	CurrentLowPassCutoff = 20000.0f;
	bDualSenseSpeakerAvailable = true;
}

void UAshenDualSenseSemanticAudioComponent::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = GetOwner())
	{
		WhisperingAudioComponent = Owner->FindComponentByClass<UAudioComponent>();
	}
}

void UAshenDualSenseSemanticAudioComponent::PlayParasiteWhisper(USoundBase* WhisperSound, float Intensity)
{
	if (!WhisperSound)
	{
		return;
	}

	if (bDualSenseSpeakerAvailable)
	{
		// DualSense: Discrete controller speaker playback
		if (WhisperingAudioComponent)
		{
			WhisperingAudioComponent->SetSound(WhisperSound);
			WhisperingAudioComponent->SetVolumeMultiplier(FMath::Clamp(Intensity, 0.20f, 1.0f));
			WhisperingAudioComponent->Play();
		}
	}
	else
	{
		// Fallback: Muffle world audio and play intimate binaural center-head sound
		UpdateAcousticFiltering(Intensity);
		if (WhisperingAudioComponent)
		{
			WhisperingAudioComponent->SetSound(WhisperSound);
			WhisperingAudioComponent->SetVolumeMultiplier(FMath::Clamp(Intensity * 1.25f, 0.30f, 1.0f));
			WhisperingAudioComponent->Play();
		}
	}
}

void UAshenDualSenseSemanticAudioComponent::UpdateAcousticFiltering(float ParasitePressure)
{
	const float ClampedPressure = FMath::Clamp(ParasitePressure, 0.0f, 1.0f);
	CurrentLowPassCutoff = FMath::Lerp(BaseWorldLowPassCutoffHz, MaxParasiteDuckingCutoffHz, ClampedPressure);
}
