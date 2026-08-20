// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticNightmareAudioComponent.h"

UAshenDiegeticNightmareAudioComponent::UAshenDiegeticNightmareAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticNightmareAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticNightmareAudioComponent::UpdateIncursionAudio(float IncursionIntensity, float SubBassVolume)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticNightmareAudioComponent: Incursion Audio updated -> Intensity: %.2f, 28Hz Sub-Bass: %.2f"),
		IncursionIntensity, SubBassVolume);
}

void UAshenDiegeticNightmareAudioComponent::PlayRealityCrackCue()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticNightmareAudioComponent: Played REALITY SUNDERING CRACK audio cue."));
}
