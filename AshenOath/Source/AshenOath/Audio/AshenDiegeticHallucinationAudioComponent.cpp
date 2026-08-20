// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticHallucinationAudioComponent.h"

UAshenDiegeticHallucinationAudioComponent::UAshenDiegeticHallucinationAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticHallucinationAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticHallucinationAudioComponent::PlayReversedWhispers()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticHallucinationAudioComponent: Diegetic reversed whispers playing in 3D audio space."));
}

void UAshenDiegeticHallucinationAudioComponent::PlayPhantomFootsteps(FVector Direction)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticHallucinationAudioComponent: False phantom footsteps sound played along vector (%f, %f, %f)"),
		Direction.X, Direction.Y, Direction.Z);
}
