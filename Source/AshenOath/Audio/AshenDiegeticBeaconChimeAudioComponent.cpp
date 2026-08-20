// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticBeaconChimeAudioComponent.h"

UAshenDiegeticBeaconChimeAudioComponent::UAshenDiegeticBeaconChimeAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticBeaconChimeAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticBeaconChimeAudioComponent::TriggerBeaconHarmonicChime()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticBeaconChimeAudioComponent: Triggered beacon harmonic chime pulse (Harmonics: %f)."), BeaconChimeHarmonics);
}
