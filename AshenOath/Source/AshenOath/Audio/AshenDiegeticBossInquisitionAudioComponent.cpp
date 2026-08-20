// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticBossInquisitionAudioComponent.h"

UAshenDiegeticBossInquisitionAudioComponent::UAshenDiegeticBossInquisitionAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticBossInquisitionAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticBossInquisitionAudioComponent::PlayPhaseChoralTransition(uint8 PhaseEnum)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticBossInquisitionAudioComponent: Phase %d Latin choral chant transition playing."), PhaseEnum);
}

void UAshenDiegeticBossInquisitionAudioComponent::PlayInquisitionBellToll()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticBossInquisitionAudioComponent: Cathedral heavy brass bell toll played."));
}
