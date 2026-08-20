// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticTrialOfWillAudioComponent.h"

UAshenDiegeticTrialOfWillAudioComponent::UAshenDiegeticTrialOfWillAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticTrialOfWillAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticTrialOfWillAudioComponent::TriggerTimeDilationAudioFilter(bool bActive)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticTrialOfWillAudioComponent: Time Dilation Audio Low-Pass Filter: %s (Heartbeat Thud Loop)"),
		bActive ? TEXT("ENGAGED") : TEXT("RELEASED"));
}
