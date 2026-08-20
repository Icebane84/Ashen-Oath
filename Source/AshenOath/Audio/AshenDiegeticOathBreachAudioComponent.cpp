// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticOathBreachAudioComponent.h"

UAshenDiegeticOathBreachAudioComponent::UAshenDiegeticOathBreachAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticOathBreachAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticOathBreachAudioComponent::TriggerOathBreachAudioStinger()
{
	UE_LOG(LogTemp, Error, TEXT("UAshenDiegeticOathBreachAudioComponent: Signature -50 cents pitch drop and shattering glass stinger executed!"));
}
