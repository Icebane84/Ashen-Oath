// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticTouchstoneChimeAudioComponent.h"

UAshenDiegeticTouchstoneChimeAudioComponent::UAshenDiegeticTouchstoneChimeAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticTouchstoneChimeAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticTouchstoneChimeAudioComponent::TriggerTouchstoneHarmonicPulse()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticTouchstoneChimeAudioComponent: Triggered touchstone harmonic chime pulse (Volume: %f)."), TouchstoneHumVolume);
}
