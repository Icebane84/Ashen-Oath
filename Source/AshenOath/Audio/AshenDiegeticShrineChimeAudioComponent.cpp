// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticShrineChimeAudioComponent.h"

UAshenDiegeticShrineChimeAudioComponent::UAshenDiegeticShrineChimeAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticShrineChimeAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticShrineChimeAudioComponent::TriggerHarmonicChimePulse()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticShrineChimeAudioComponent: Triggered harmonic chime pulse (Resonance: %f)"), ChimeHarmonicResonance);
}
