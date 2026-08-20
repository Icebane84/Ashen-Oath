// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 784: Ashen Oathbringer Resonance Synergy Calculator

#include "AshenOathbringerResonanceSynergyCalculator.h"

float UAshenOathbringerResonanceSynergyCalculator::CalculateResonancePartyBuff(float ResonancePercent)
{
	const float BuffPercent = (ResonancePercent >= 100.0f) ? 30.0f : (ResonancePercent * 0.2f);
	OnSynergyCalculated.Broadcast(ResonancePercent, BuffPercent);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerResonanceSynergyCalculator: RESONANCE PARTY BUFF CALCULATED -> Resonance: %.1f%% | Party Damage Buff: +%.1f%%."),
		ResonancePercent, BuffPercent);

	return BuffPercent;
}
