// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticShadowMarkAudioComponent.h"

UAshenDiegeticShadowMarkAudioComponent::UAshenDiegeticShadowMarkAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticShadowMarkAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticShadowMarkAudioComponent::TriggerShadowMarkCrackleHum(float EmissiveIntensity)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticShadowMarkAudioComponent: Shadow mark crackle hum triggered at emissive intensity %.2f"), EmissiveIntensity);
}
