// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticEcosystemAudioComponent.h"

UAshenDiegeticEcosystemAudioComponent::UAshenDiegeticEcosystemAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticEcosystemAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticEcosystemAudioComponent::PlaySymbioticResonanceHarmonicHum()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticEcosystemAudioComponent: Playing Symbiotic Resonance Harmonic Chord Alignment."));
}
