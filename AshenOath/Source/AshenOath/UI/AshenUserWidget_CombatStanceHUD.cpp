// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_CombatStanceHUD.h"

void UAshenUserWidget_CombatStanceHUD::UpdateStanceHUD(ECombatStance InStance, float InCooldown)
{
	DisplayedStance = InStance;
	StanceCooldownRemaining = FMath::Max(0.0f, InCooldown);

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CombatStanceHUD: Updated Stance HUD -> Stance: %d, Cooldown: %.1fs"),
		static_cast<int32>(DisplayedStance), StanceCooldownRemaining);
}
