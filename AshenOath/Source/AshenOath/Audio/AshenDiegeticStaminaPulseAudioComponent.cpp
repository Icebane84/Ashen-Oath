// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDiegeticStaminaPulseAudioComponent.h"

UAshenDiegeticStaminaPulseAudioComponent::UAshenDiegeticStaminaPulseAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDiegeticStaminaPulseAudioComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenDiegeticStaminaPulseAudioComponent::UpdateCardiacPulse(float CurrentStaminaRatio)
{
	bIsPulseActive = CurrentStaminaRatio <= 0.35f;
	const float PulseFrequency = FMath::Lerp(2.5f, 0.8f, FMath::Clamp(CurrentStaminaRatio, 0.0f, 1.0f));
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticStaminaPulseAudioComponent: Cardiac pulse playing at %.2f Hz (Stamina: %.1f%%, Active: %s)."),
		PulseFrequency, CurrentStaminaRatio * 100.0f, bIsPulseActive ? TEXT("TRUE") : TEXT("FALSE"));
}

void UAshenDiegeticStaminaPulseAudioComponent::UpdateStaminaPulseState(float CurrentStamina, float MaxStamina)
{
	const float SafeMax = FMath::Max(MaxStamina, 1.0f);
	UpdateCardiacPulse(CurrentStamina / SafeMax);
}
