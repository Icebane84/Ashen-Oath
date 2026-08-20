// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/UAshenRelationalTrustLevelThresholdCalculator.h"

int32 UAshenRelationalTrustLevelThresholdCalculator::CalculateTrustTier(float TrustValue)
{
	if (TrustValue >= 0.85f) return 3; // Sworn Covenant
	if (TrustValue >= 0.50f) return 2; // Trusted Ally
	if (TrustValue >= 0.20f) return 1; // Acquaintance
	return 0; // Hostile/Distant
}
