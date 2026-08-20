// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 169: Ashen Stamina Bar UMG Widget

#include "AshenUserWidget_StaminaBar.h"

void UAshenUserWidget_StaminaBar::UpdateStamina(float CurrentStamina, float MaxStamina)
{
	if (MaxStamina <= 0.0f) return;

	const float PrevPercent = CurrentStaminaPercent;
	CurrentStaminaPercent = FMath::Clamp(CurrentStamina / MaxStamina, 0.0f, 1.0f);

	// Trigger exhaustion pulse when stamina first hits zero
	if (PrevPercent > 0.0f && CurrentStaminaPercent <= 0.0f)
	{
		bIsExhausted = true;
		TriggerExhaustionPulse();
	}
	else if (CurrentStaminaPercent > 0.25f)
	{
		bIsExhausted = false;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_StaminaBar: Stamina %.1f pct (exhausted: %s)."),
		CurrentStaminaPercent * 100.0f, bIsExhausted ? TEXT("YES") : TEXT("no"));
}

void UAshenUserWidget_StaminaBar::TriggerExhaustionPulse()
{
	OnExhaustionPulse.Broadcast();
	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_StaminaBar: EXHAUSTION PULSE triggered — stamina depleted."));
}
