// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticWeavingAudioComponent.h"

UAshenDiegeticWeavingAudioComponent::UAshenDiegeticWeavingAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticWeavingAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticWeavingAudioComponent::PlayThreadPluckSFX(float Tension)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticWeavingAudioComponent: Playing High-Tension Light Filament Violin Pluck SFX (Tension: %.2f)"),
		Tension);
}

void UAshenDiegeticWeavingAudioComponent::PlayThreadSnapRuptureSFX()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticWeavingAudioComponent: Playing VIOLENT FILAMENT SNAP & RUPTURE SFX!"));
}
