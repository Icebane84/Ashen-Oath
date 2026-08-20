// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_TraversalStaminaHUD.h"

void UAshenUserWidget_TraversalStaminaHUD::UpdateTraversalHUD(float InStamina, int32 InCharges)
{
	StaminaPercent = FMath::Clamp(InStamina * 100.0f, 0.0f, 100.0f);
	AvailableDashCharges = InCharges;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_TraversalStaminaHUD: Traversal HUD -> Stamina: %.1f%%, Dash Charges: %d"),
		StaminaPercent, AvailableDashCharges);
}
