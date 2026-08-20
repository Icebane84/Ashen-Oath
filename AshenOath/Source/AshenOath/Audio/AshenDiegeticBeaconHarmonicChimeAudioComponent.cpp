// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticBeaconHarmonicChimeAudioComponent.h"

UAshenDiegeticBeaconHarmonicChimeAudioComponent::UAshenDiegeticBeaconHarmonicChimeAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticBeaconHarmonicChimeAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticBeaconHarmonicChimeAudioComponent::TriggerBeaconHarmonicChimePulse()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticBeaconHarmonicChimeAudioComponent: Triggered beacon harmonic chime pulse (Volume: %f)."), BeaconHarmonicVolume);
}
