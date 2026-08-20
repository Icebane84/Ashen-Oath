// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSomaticBreathingRateModulator.h"

UAshenSomaticBreathingRateModulator::UAshenSomaticBreathingRateModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticBreathingRateModulator::UpdateBreathingRate(float Debt, float Resolve)
{
	BreathingRateScalar = FMath::Clamp(1.0f + (Debt * 1.5f) - (Resolve * 0.5f), 0.5f, 3.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticBreathingRateModulator: Breathing rate scalar updated to %.2f"), BreathingRateScalar);
}
