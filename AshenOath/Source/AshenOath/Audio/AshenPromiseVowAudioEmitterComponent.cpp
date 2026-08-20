// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenPromiseVowAudioEmitterComponent.h"
#include "Components/AudioComponent.h"

UAshenPromiseVowAudioEmitterComponent::UAshenPromiseVowAudioEmitterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentVolume = 1.0f;
}

void UAshenPromiseVowAudioEmitterComponent::PlayVowResonanceCue(EPromiseResolutionStatus Status)
{
	switch (Status)
	{
	case EPromiseResolutionStatus::Active:
		CurrentVolume = 1.20f;
		break;
	case EPromiseResolutionStatus::Fulfilled:
		CurrentVolume = 1.50f;
		break;
	case EPromiseResolutionStatus::Betrayed:
		CurrentVolume = 0.50f; // Distorted low dissonance
		break;
	default:
		CurrentVolume = 1.0f;
		break;
	}

	if (VowAudioComponent)
	{
		VowAudioComponent->SetVolumeMultiplier(CurrentVolume);
	}
}
