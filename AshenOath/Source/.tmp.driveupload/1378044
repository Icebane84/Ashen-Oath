// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 683: Ashen Martyr Guard Corruption Spike Calculator

#include "AshenMartyrGuardCorruptionSpikeCalculator.h"

float UAshenMartyrGuardCorruptionSpikeCalculator::CalculateMartyrCorruptionSpike(float InterceptedLethalDamage, float CurrentCorruption)
{
	const float Spike = FMath::Clamp(InterceptedLethalDamage * 0.15f, 5.0f, 40.0f);
	const float TotalCorruption = FMath::Clamp(CurrentCorruption + Spike, 0.0f, 100.0f);

	OnCorruptionSpikeCalculated.Broadcast(Spike, TotalCorruption);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMartyrGuardCorruptionSpikeCalculator: MARTYR CORRUPTION SPIKE CALCULATED -> Intercepted Damage: %.1f | Spike: +%.1f | Total Corruption: %.1f."),
		InterceptedLethalDamage, Spike, TotalCorruption);

	return Spike;
}
