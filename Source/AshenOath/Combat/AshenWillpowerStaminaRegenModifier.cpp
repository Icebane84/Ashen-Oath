// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 678: Ashen Willpower Stamina Regen Modifier

#include "AshenWillpowerStaminaRegenModifier.h"

float UAshenWillpowerStaminaRegenModifier::ModifyStaminaRegenRate(float BaseRegenRate, bool bIsUnbrokenActive)
{
	const float Multiplier = bIsUnbrokenActive ? 1.5f : 1.0f; // +50% recovery rate
	ActiveRegenRate = BaseRegenRate * Multiplier;
	const bool bReplenish = bIsUnbrokenActive;

	OnStaminaRegenModified.Broadcast(ActiveRegenRate, bReplenish);

	UE_LOG(LogTemp, Warning, TEXT("UAshenWillpowerStaminaRegenModifier: STAMINA REGEN MODIFIED -> Base: %.1f | Rate: %.1f (+%.0f%%) | Instant Replenish: %s."),
		BaseRegenRate, ActiveRegenRate, (Multiplier - 1.0f) * 100.0f, bReplenish ? TEXT("TRUE") : TEXT("FALSE"));

	return ActiveRegenRate;
}
