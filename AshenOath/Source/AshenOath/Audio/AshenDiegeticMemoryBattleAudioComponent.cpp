// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticMemoryBattleAudioComponent.h"

UAshenDiegeticMemoryBattleAudioComponent::UAshenDiegeticMemoryBattleAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticMemoryBattleAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticMemoryBattleAudioComponent::TriggerMemoryBattleStinger(int32 BattlePhase)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticMemoryBattleAudioComponent: Battle stinger triggered for phase %d"), BattlePhase);
}
