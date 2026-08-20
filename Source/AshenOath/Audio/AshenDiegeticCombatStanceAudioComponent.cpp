// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticCombatStanceAudioComponent.h"

UAshenDiegeticCombatStanceAudioComponent::UAshenDiegeticCombatStanceAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticCombatStanceAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticCombatStanceAudioComponent::PlayStanceTransitionAudio(ECombatStance NewStance)
{
	FString SoundCue = TEXT("Flow Wind Chime");
	if (NewStance == ECombatStance::Aegis) SoundCue = TEXT("Aegis Iron Shield Clang");
	else if (NewStance == ECombatStance::Berserk) SoundCue = TEXT("Berserk Blood Rush Heartbeat");

	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCombatStanceAudioComponent: Played '%s' stance transition audio."), *SoundCue);
}

void UAshenDiegeticCombatStanceAudioComponent::PlayFlankCriticalImpactCue()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticCombatStanceAudioComponent: Played FLANK CRITICAL 2.0x IMPACT AUDIO CUE."));
}
