// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticBreathingAudioComponent.h"

UAshenDiegeticBreathingAudioComponent::UAshenDiegeticBreathingAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticBreathingAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticBreathingAudioComponent::PlayRaggedBreath(bool bIsInhale)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticBreathingAudioComponent: Playing Diegetic Breath SFX: %s"),
		bIsInhale ? TEXT("STRAINED INHALE") : TEXT("RAGGED EXHALE"));
}
