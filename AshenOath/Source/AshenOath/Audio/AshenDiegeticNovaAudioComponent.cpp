// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticNovaAudioComponent.h"

UAshenDiegeticNovaAudioComponent::UAshenDiegeticNovaAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticNovaAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticNovaAudioComponent::UpdateNovaAudioTelemetry(float KaelenCorruption, float SerafinaBurnout, float IntegrationDebt)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticNovaAudioComponent: Nova Audio Telemetry -> Corruption: %.2f, Burnout: %.2f, Debt: %.2f"),
		KaelenCorruption, SerafinaBurnout, IntegrationDebt);
}

void UAshenDiegeticNovaAudioComponent::PlayNovaDetonationCue()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticNovaAudioComponent: Played EMPATHIC CONDUIT NOVA DETONATION CUE."));
}
