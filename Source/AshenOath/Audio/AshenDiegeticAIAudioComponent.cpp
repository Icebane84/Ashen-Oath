// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticAIAudioComponent.h"

UAshenDiegeticAIAudioComponent::UAshenDiegeticAIAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticAIAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticAIAudioComponent::TriggerAttackTelegraphAudio()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAIAudioComponent: Triggered attack telegraph audio cue (Volume: %f)."), TelegraphAudioVolume);
}

void UAshenDiegeticAIAudioComponent::TriggerPunishWindowOpportunityAudio()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticAIAudioComponent: Triggered punish window opportunity audio cue."));
}
