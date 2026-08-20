// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticResonanceAudioSpatializerComponent.h"

UAshenDiegeticResonanceAudioSpatializerComponent::UAshenDiegeticResonanceAudioSpatializerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticResonanceAudioSpatializerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticResonanceAudioSpatializerComponent::UpdateSpatializedResonanceFrequencies(float PostureScalar)
{
	SpatializedResonanceVolume = FMath::Clamp(PostureScalar, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticResonanceAudioSpatializerComponent: Spatialized resonance volume updated to %f"), SpatializedResonanceVolume);
}
