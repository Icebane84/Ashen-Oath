// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 719: Ashen CAN Sanctuary Surplus Mastery Calculator

#include "AshenCANSanctuarySurplusMasteryCalculator.h"

int32 UAshenCANSanctuarySurplusMasteryCalculator::CalculateSanctuarySurplusBonus(int32 BaseResources, float SerafinaEmpathicHealthPercent)
{
	const float Multiplier = 1.0f + (SerafinaEmpathicHealthPercent / 100.0f) * 0.5f; // Up to +50% bonus resources
	const int32 Bonus = FMath::RoundToInt(BaseResources * Multiplier);

	OnSurplusCalculated.Broadcast(Bonus, Multiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCANSanctuarySurplusMasteryCalculator: SANCTUARY SURPLUS CALCULATED -> Base: %d | Empathic Health: %.1f%% -> Total: %d resources (%.2fx)."),
		BaseResources, SerafinaEmpathicHealthPercent, Bonus, Multiplier);

	return Bonus;
}
