// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticAscensionChimeAudioComponent.h"

UAshenDiegeticAscensionChimeAudioComponent::UAshenDiegeticAscensionChimeAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticAscensionChimeAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticAscensionChimeAudioComponent::TriggerAscensionHarmonicChimePulse()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAscensionChimeAudioComponent: Triggered ascension harmonic chime pulse (Harmonics: %f)."), AscensionChimeHarmonics);
}
