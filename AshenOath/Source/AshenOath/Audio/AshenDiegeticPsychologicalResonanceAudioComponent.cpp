// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticPsychologicalResonanceAudioComponent.h"

UAshenDiegeticPsychologicalResonanceAudioComponent::UAshenDiegeticPsychologicalResonanceAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticPsychologicalResonanceAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticPsychologicalResonanceAudioComponent::UpdatePsychologicalResonanceHarmonics(float EchoStrength)
{
	PsychologicalResonanceVolume = FMath::Clamp(EchoStrength, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticPsychologicalResonanceAudioComponent: Updated psychological resonance volume to %f"), PsychologicalResonanceVolume);
}
