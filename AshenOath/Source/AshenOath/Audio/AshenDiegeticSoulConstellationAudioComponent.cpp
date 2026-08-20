// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticSoulConstellationAudioComponent.h"

UAshenDiegeticSoulConstellationAudioComponent::UAshenDiegeticSoulConstellationAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticSoulConstellationAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticSoulConstellationAudioComponent::TriggerHeartstoneResonanceChime()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticSoulConstellationAudioComponent: Triggered Heartstone resonance chime (Volume=%f)."), HeartstoneResonanceVolume);
}

void UAshenDiegeticSoulConstellationAudioComponent::TriggerDebtEscalationDrone(float DebtLevel)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticSoulConstellationAudioComponent: Triggered Integration Debt escalation drone (DebtLevel=%f)."), DebtLevel);
}
