// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticResonanceChimeAudioComponent.h"

UAshenDiegeticResonanceChimeAudioComponent::UAshenDiegeticResonanceChimeAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticResonanceChimeAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticResonanceChimeAudioComponent::TriggerResonanceHarmonicChimePulse()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticResonanceChimeAudioComponent: Triggered resonance harmonic chime pulse (Volume: %f)."), ResonanceChimeVolume);
}
