// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenRelationalTrustRecoveryCalculator.h"

float UAshenRelationalTrustRecoveryCalculator::CalculateTrustRecovery(float CurrentTrust, float TacticalSynergyRating)
{
	float NewTrust = FMath::Clamp(CurrentTrust + (TacticalSynergyRating * 0.15f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenRelationalTrustRecoveryCalculator: Trust recovered from %.2f to %.2f (Synergy: %.2f)"), CurrentTrust, NewTrust, TacticalSynergyRating);
	return NewTrust;
}
