// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticTriageAudioComponent.h"

UAshenDiegeticTriageAudioComponent::UAshenDiegeticTriageAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticTriageAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticTriageAudioComponent::PlayMuffledCoughSFX()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenDiegeticTriageAudioComponent: Playing Serafina's Muffled Wet Cough SFX (Black Sap)."));
}

void UAshenDiegeticTriageAudioComponent::PlayBandageUnwrapSFX()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticTriageAudioComponent: Playing Stained Linen Bandage Unwrapping SFX."));
}
