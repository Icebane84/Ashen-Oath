// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticTouchstoneHumAudioComponent.h"

UAshenDiegeticTouchstoneHumAudioComponent::UAshenDiegeticTouchstoneHumAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticTouchstoneHumAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticTouchstoneHumAudioComponent::UpdateHumProximityVolume(float DistanceToPlayer)
{
	TouchstoneHumVolume = FMath::Clamp(1.0f - (DistanceToPlayer / 1000.0f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticTouchstoneHumAudioComponent: Touchstone hum volume updated to %f"), TouchstoneHumVolume);
}
