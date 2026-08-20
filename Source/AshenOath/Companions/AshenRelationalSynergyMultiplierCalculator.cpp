// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenRelationalSynergyMultiplierCalculator.h"

float UAshenRelationalSynergyMultiplierCalculator::CalculatePartySynergyMultiplier(float GarrettTrust, float SerafinaTrust)
{
	float SynergyMultiplier = 1.0f + (GarrettTrust * 0.25f) + (SerafinaTrust * 0.25f);
	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalSynergyMultiplierCalculator: Party synergy multiplier calculated as %.2f"), SynergyMultiplier);
	return SynergyMultiplier;
}
