// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 687: Ashen Serafina Empathic Exhaustion Modulator

#include "AshenSerafinaEmpathicExhaustionModulator.h"

float UAshenSerafinaEmpathicExhaustionModulator::ModulateSerafinaHealingOutput(float BaseHealing, float KaelenStainPercent)
{
	const float Penalty = (KaelenStainPercent / 100.0f) * 0.5f; // Up to 50% penalty
	const float EffectiveOutput = BaseHealing * (1.0f - Penalty);
	const bool bExceeded = (KaelenStainPercent > 40.0f);

	OnExhaustionModulated.Broadcast(EffectiveOutput, bExceeded);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaEmpathicExhaustionModulator: SERAFINA HEALING MODULATED -> Base: %.1f HP | Stain: %.1f%% -> Effective: %.1f HP | Exhausted: %s."),
		BaseHealing, KaelenStainPercent, EffectiveOutput, bExceeded ? TEXT("TRUE") : TEXT("FALSE"));

	return EffectiveOutput;
}
