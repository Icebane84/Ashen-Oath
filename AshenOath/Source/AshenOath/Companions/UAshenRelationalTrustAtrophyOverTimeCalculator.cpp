// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/UAshenRelationalTrustAtrophyOverTimeCalculator.h"

float UAshenRelationalTrustAtrophyOverTimeCalculator::CalculateAtrophiedTrust(float InitialTrust, float SeparationHours)
{
	float AtrophiedTrust = FMath::Clamp(InitialTrust - (SeparationHours * 0.015f), 0.1f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalTrustAtrophyOverTimeCalculator: Atrophied trust calculated as %.2f (Separation: %.1fh)"), AtrophiedTrust, SeparationHours);
	return AtrophiedTrust;
}
