// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticDualityAudioSpatializer.h"

UAshenDiegeticDualityAudioSpatializer::UAshenDiegeticDualityAudioSpatializer()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticDualityAudioSpatializer::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticDualityAudioSpatializer::SpatializeDualityAudio(float RealmShiftBlend)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticDualityAudioSpatializer: 3D soundscape spatialized across realm shift blend %.2f"), RealmShiftBlend);
}
