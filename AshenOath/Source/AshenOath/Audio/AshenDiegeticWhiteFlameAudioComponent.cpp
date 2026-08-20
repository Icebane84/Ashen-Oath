// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticWhiteFlameAudioComponent.h"

UAshenDiegeticWhiteFlameAudioComponent::UAshenDiegeticWhiteFlameAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticWhiteFlameAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticWhiteFlameAudioComponent::PlayWhiteFlameIgnitionSFX()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticWhiteFlameAudioComponent: Playing Incandescent White Flame Ignition SFX (Choir Swell + Bell Chime)!"));
}

void UAshenDiegeticWhiteFlameAudioComponent::PlayPyreCleaveImpactSFX()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticWhiteFlameAudioComponent: Playing Holy-Kinetic White Pyre Cleave Impact SFX."));
}
