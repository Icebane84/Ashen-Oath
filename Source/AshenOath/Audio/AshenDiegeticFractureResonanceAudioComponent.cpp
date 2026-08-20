// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticFractureResonanceAudioComponent.h"

UAshenDiegeticFractureResonanceAudioComponent::UAshenDiegeticFractureResonanceAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticFractureResonanceAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticFractureResonanceAudioComponent::TriggerFractureResonancePulse(float InstabilityIndex)
{
	FractureChimePitch = 1.0f + (InstabilityIndex * 0.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticFractureResonanceAudioComponent: Triggered fracture resonance pulse (Pitch: %f)"), FractureChimePitch);
}
