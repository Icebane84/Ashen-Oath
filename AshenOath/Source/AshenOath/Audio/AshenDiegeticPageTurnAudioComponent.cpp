// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenDiegeticPageTurnAudioComponent.h"

UAshenDiegeticPageTurnAudioComponent::UAshenDiegeticPageTurnAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticPageTurnAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDiegeticPageTurnAudioComponent::TriggerPageTurnSFX()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticPageTurnAudioComponent: Triggered page turn SFX (Volume: %f)."), PageTurnVolume);
}

void UAshenDiegeticPageTurnAudioComponent::TriggerCharcoalScrawlSFX()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticPageTurnAudioComponent: Triggered charcoal scrawl SFX."));
}
