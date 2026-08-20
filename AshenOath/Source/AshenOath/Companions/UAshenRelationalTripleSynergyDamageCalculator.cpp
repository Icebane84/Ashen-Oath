// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/UAshenRelationalTripleSynergyDamageCalculator.h"

float UAshenRelationalTripleSynergyDamageCalculator::CalculateTripleSynergyMultiplier(float GarrettTrust, float SerafinaTrust, float Resolve)
{
	float BaseMultiplier = 1.5f;
	float TrustBonus = (GarrettTrust + SerafinaTrust) * 0.75f;
	float ResolveBonus = Resolve * 0.25f;
	return BaseMultiplier + TrustBonus + ResolveBonus;
}
