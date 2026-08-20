// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenSoulIdentityTriadCalculator.h"

float UAshenSoulIdentityTriadCalculator::CalculateIdentityStability(const FSoulStateVector& SoulState)
{
	float Stability = (SoulState.Resolve * 0.5f) + ((1.0f - SoulState.Corruption) * 0.3f) + ((1.0f - SoulState.Isolation) * 0.2f);
	return FMath::Clamp(Stability, 0.0f, 1.0f);
}

FSoulStateVector UAshenSoulIdentityTriadCalculator::NormalizeSoulStateVector(const FSoulStateVector& RawState)
{
	FSoulStateVector Clean = RawState;
	Clean.Resolve = FMath::Clamp(RawState.Resolve, 0.0f, 1.0f);
	Clean.Corruption = FMath::Clamp(RawState.Corruption, 0.0f, 1.0f);
	Clean.Isolation = FMath::Clamp(RawState.Isolation, 0.0f, 1.0f);
	Clean.GarrettTrust = FMath::Clamp(RawState.GarrettTrust, 0.0f, 1.0f);
	Clean.SerafinaTrust = FMath::Clamp(RawState.SerafinaTrust, 0.0f, 1.0f);
	return Clean;
}
