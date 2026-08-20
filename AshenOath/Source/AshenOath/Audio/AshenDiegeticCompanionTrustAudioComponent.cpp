// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticCompanionTrustAudioComponent.h"

UAshenDiegeticCompanionTrustAudioComponent::UAshenDiegeticCompanionTrustAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticCompanionTrustAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticCompanionTrustAudioComponent::TriggerResonanceHarmonyChord()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCompanionTrustAudioComponent: Resonance harmony chord triggered!"));
}

void UAshenDiegeticCompanionTrustAudioComponent::TriggerDivergenceDiscordDrone(float TrustDivergenceDelta)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticCompanionTrustAudioComponent: Divergence discord drone triggered (Delta=%f)"), TrustDivergenceDelta);
}
