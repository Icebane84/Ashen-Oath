// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticShadowSeepageAudioComponent.h"

UAshenDiegeticShadowSeepageAudioComponent::UAshenDiegeticShadowSeepageAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticShadowSeepageAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticShadowSeepageAudioComponent::UpdateSeepageAudio(EShadowSeepagePhase Phase, float Corruption)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticShadowSeepageAudioComponent: Seepage Audio updated -> Phase: %d, Corruption: %.2f"),
		static_cast<int32>(Phase), Corruption);
}

void UAshenDiegeticShadowSeepageAudioComponent::PlayCrimsonStaticBurstCue()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticShadowSeepageAudioComponent: Played CRIMSON STATIC BURST CUE."));
}
