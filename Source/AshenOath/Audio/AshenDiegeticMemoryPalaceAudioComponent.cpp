// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticMemoryPalaceAudioComponent.h"

UAshenDiegeticMemoryPalaceAudioComponent::UAshenDiegeticMemoryPalaceAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticMemoryPalaceAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticMemoryPalaceAudioComponent::UpdateLocusAudioResonance(float ProximityIntensity, float ResonanceFrequency)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticMemoryPalaceAudioComponent: Locus Resonance updated -> Intensity: %.2f, Freq: %.1f Hz"),
		ProximityIntensity, ResonanceFrequency);
}

void UAshenDiegeticMemoryPalaceAudioComponent::PlayReconstructionChime()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticMemoryPalaceAudioComponent: Played CRYSTALLINE RECONSTRUCTION HARMONIC CHIME."));
}
