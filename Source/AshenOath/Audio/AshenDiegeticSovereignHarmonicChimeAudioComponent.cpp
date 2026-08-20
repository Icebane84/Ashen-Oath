// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticSovereignHarmonicChimeAudioComponent.h"

UAshenDiegeticSovereignHarmonicChimeAudioComponent::UAshenDiegeticSovereignHarmonicChimeAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticSovereignHarmonicChimeAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticSovereignHarmonicChimeAudioComponent::TriggerSovereignHarmonicChimePulse()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticSovereignHarmonicChimeAudioComponent: Triggered sovereign harmonic chime pulse (Volume: %f)."), SovereignHarmonicVolume);
}
