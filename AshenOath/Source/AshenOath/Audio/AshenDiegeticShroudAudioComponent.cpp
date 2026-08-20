// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticShroudAudioComponent.h"

UAshenDiegeticShroudAudioComponent::UAshenDiegeticShroudAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticShroudAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticShroudAudioComponent::PlaySpectralPhaseSound()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticShroudAudioComponent: Eerie spectral phasing whoosh sound played."));
}

void UAshenDiegeticShroudAudioComponent::PlayPurifierFlameRoar()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticShroudAudioComponent: Searing white holy flame roar sound played."));
}
