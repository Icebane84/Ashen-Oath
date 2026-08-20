// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenRelationalTrustAtrophyCalculator.h"

float UAshenRelationalTrustAtrophyCalculator::CalculateTrustAtrophy(float CurrentTrust, int32 IgnoredAdviceCount)
{
	float Decay = FMath::Min(IgnoredAdviceCount * 0.05f, 0.40f);
	float NewTrust = FMath::Clamp(CurrentTrust - Decay, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalTrustAtrophyCalculator: Trust decay calculated -> NewTrust: %.2f (Ignored: %d)"), NewTrust, IgnoredAdviceCount);
	return NewTrust;
}
