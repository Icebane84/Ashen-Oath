// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticIntimateAudioComponent.h"

UAshenDiegeticIntimateAudioComponent::UAshenDiegeticIntimateAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticIntimateAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticIntimateAudioComponent::UpdateSomaticHeartbeat(float StrainScalar)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticIntimateAudioComponent: Somatic Heartbeat Frequency modulated -> Strain: %.2f"),
		StrainScalar);
}
