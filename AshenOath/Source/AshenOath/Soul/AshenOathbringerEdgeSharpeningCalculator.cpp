// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 778: Ashen Oathbringer Edge Sharpening Calculator

#include "AshenOathbringerEdgeSharpeningCalculator.h"

UAshenOathbringerEdgeSharpeningCalculator::UAshenOathbringerEdgeSharpeningCalculator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenOathbringerEdgeSharpeningCalculator::CalculatePhysicalDamageMultiplier(int32 SharpeningTier)
{
	const float Mult = 1.0f + (SharpeningTier * 0.15f); // +15% damage per sharpening tier
	OnSharpeningCalculated.Broadcast(SharpeningTier, Mult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerEdgeSharpeningCalculator: EDGE SHARPENING CALCULATED -> Tier: %d | Physical Damage Multiplier: %.2fx."),
		SharpeningTier, Mult);

	return Mult;
}
