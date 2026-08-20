// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticBossEncounterAudioComponent.h"

UAshenDiegeticBossEncounterAudioComponent::UAshenDiegeticBossEncounterAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticBossEncounterAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticBossEncounterAudioComponent::TransitionPhaseMusic(EBossPhaseState Phase)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticBossEncounterAudioComponent: Transitioning Boss Music Layer -> Phase %d"),
		static_cast<int32>(Phase));
}

void UAshenDiegeticBossEncounterAudioComponent::PlayCataclysmTremorSFX()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticBossEncounterAudioComponent: Playing Sub-Bass Cataclysm Void Tremor SFX!"));
}
