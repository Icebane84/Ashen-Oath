// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenTraumaSomaticsHapticBridge.h"

UAshenTraumaSomaticsHapticBridge::UAshenTraumaSomaticsHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenTraumaSomaticsHapticBridge::EvaluateSomaticHaptics(
	float HeartRateBPM,
	float BladeSootScalar,
	float& OutHeartPulseIntervalSeconds,
	float& OutRightTriggerSlagResistance) const
{
	const float SafeBPM = FMath::Clamp(HeartRateBPM, 60.0f, 170.0f);
	OutHeartPulseIntervalSeconds = 60.0f / SafeBPM;
	OutRightTriggerSlagResistance = FMath::Clamp(BladeSootScalar * 0.75f, 0.0f, 0.75f);
}
