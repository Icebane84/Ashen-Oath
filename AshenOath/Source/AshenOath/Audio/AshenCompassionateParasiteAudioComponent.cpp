// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenCompassionateParasiteAudioComponent.h"

UAshenCompassionateParasiteAudioComponent::UAshenCompassionateParasiteAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompassionateParasiteAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCompassionateParasiteAudioComponent::TriggerTailoredParasiteWhisper(FName HabitContext)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenCompassionateParasiteAudioComponent: Triggered tailored parasite whisper for habit context %s"), *HabitContext.ToString());
}
