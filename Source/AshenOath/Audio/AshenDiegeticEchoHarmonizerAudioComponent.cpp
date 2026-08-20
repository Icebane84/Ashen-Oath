// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticEchoHarmonizerAudioComponent.h"

UAshenDiegeticEchoHarmonizerAudioComponent::UAshenDiegeticEchoHarmonizerAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticEchoHarmonizerAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticEchoHarmonizerAudioComponent::UpdateEchoHarmonizerFrequency(float PhaseShiftIntensity)
{
	EchoHarmonizerVolume = FMath::Clamp(PhaseShiftIntensity, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticEchoHarmonizerAudioComponent: Echo harmonizer volume updated to %f"), EchoHarmonizerVolume);
}
