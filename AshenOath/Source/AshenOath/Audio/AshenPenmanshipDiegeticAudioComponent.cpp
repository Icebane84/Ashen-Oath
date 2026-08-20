// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenPenmanshipDiegeticAudioComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"

UAshenPenmanshipDiegeticAudioComponent::UAshenPenmanshipDiegeticAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenPenmanshipDiegeticAudioComponent::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = GetOwner())
	{
		InscriptionAudioComponent = Owner->FindComponentByClass<UAudioComponent>();
	}
}

void UAshenPenmanshipDiegeticAudioComponent::PlayPenmanshipSound(
	EMarginaliaAuthor Author,
	USoundBase* CueSound)
{
	if (CueSound && InscriptionAudioComponent)
	{
		InscriptionAudioComponent->SetSound(CueSound);
		InscriptionAudioComponent->Play();
	}
}
