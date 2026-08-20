// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_StaminaPulseHUD.h"

void UAshenUserWidget_StaminaPulseHUD::UpdateStaminaPulseDisplay(float CurrentStamina, float MaxStamina)
{
	const float SafeMax = FMath::Max(MaxStamina, 1.0f);
	StaminaRatio = FMath::Clamp(CurrentStamina / SafeMax, 0.0f, 1.0f);
	HeartPulseScale = 1.0f + (1.0f - StaminaRatio) * 0.35f;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_StaminaPulseHUD: Stamina: %.1f%% | Pulse Scale: %.2f"),
		StaminaRatio * 100.0f, HeartPulseScale);
}
