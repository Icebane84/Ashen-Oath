// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 461: Ashen Diegetic Breathing Component

#include "AshenDiegeticBreathingComponent.h"

UAshenDiegeticBreathingComponent::UAshenDiegeticBreathingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CalculatedBreathingRateHz = 0.5f;
	CalculatedFatiguePercent = 0.0f;
}

void UAshenDiegeticBreathingComponent::UpdateBreathingFatigue(float CurrentStamina, float MaxStamina)
{
	const float SafeMax = FMath::Max(1.0f, MaxStamina);
	CalculatedFatiguePercent = FMath::Clamp(1.0f - (CurrentStamina / SafeMax), 0.0f, 1.0f);
	CalculatedBreathingRateHz = 0.5f + (CalculatedFatiguePercent * 2.0f); // 0.5Hz resting -> 2.5Hz exhausted

	FName AudioBarkTag = (CalculatedFatiguePercent > 0.7f) ? FName(TEXT("Audio.Breathing.HeavyPanting")) : FName(TEXT("Audio.Breathing.Normal"));

	OnBreathingUpdated.Broadcast(CalculatedBreathingRateHz, CalculatedFatiguePercent, AudioBarkTag);

	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticBreathingComponent: BREATHING UPDATED — Rate: %.2f Hz | Fatigue: %.1f%% [%s]"),
		CalculatedBreathingRateHz, CalculatedFatiguePercent * 100.0f, *AudioBarkTag.ToString());
}
