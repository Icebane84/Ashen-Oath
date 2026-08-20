// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/UAshenRelationalSynergyComboDamageCalculator.h"

float UAshenRelationalSynergyComboDamageCalculator::CalculateComboDamageMultiplier(float GarrettTrust, float SerafinaTrust, float KaelenResolve)
{
	float AverageTrust = (GarrettTrust + SerafinaTrust) * 0.5f;
	float Multiplier = 1.0f + (AverageTrust * 0.5f) + (KaelenResolve * 0.25f);
	return Multiplier;
}
