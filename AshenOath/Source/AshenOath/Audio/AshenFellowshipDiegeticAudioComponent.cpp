// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenFellowshipDiegeticAudioComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"

UAshenFellowshipDiegeticAudioComponent::UAshenFellowshipDiegeticAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenFellowshipDiegeticAudioComponent::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = GetOwner())
	{
		BreathingAudioComponent = Owner->FindComponentByClass<UAudioComponent>();
	}
}

void UAshenFellowshipDiegeticAudioComponent::UpdateRelationalAudio(
	ERelationalRuptureState RuptureState,
	float TrioResonance)
{
	if (!BreathingAudioComponent)
	{
		return;
	}

	if (RuptureState == ERelationalRuptureState::RememberedReconciliation || TrioResonance >= 0.75f)
	{
		BreathingAudioComponent->SetPitchMultiplier(1.0f);
		BreathingAudioComponent->SetVolumeMultiplier(0.70f);
	}
	else if (RuptureState == ERelationalRuptureState::ActiveRupture)
	{
		BreathingAudioComponent->SetPitchMultiplier(0.85f);
		BreathingAudioComponent->SetVolumeMultiplier(0.30f);
	}
}

void UAshenFellowshipDiegeticAudioComponent::PlayWordlessAcknowledgement(USoundBase* CueSound)
{
	if (CueSound && BreathingAudioComponent)
	{
		BreathingAudioComponent->SetSound(CueSound);
		BreathingAudioComponent->Play();
	}
}
