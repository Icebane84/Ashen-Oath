// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenBioAcousticHeartbeatEvaluator.h"

UAshenBioAcousticHeartbeatEvaluator::UAshenBioAcousticHeartbeatEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenBioAcousticHeartbeatEvaluator::EvaluateHeartRateBPM(bool bInCombat, float VeinCorruption) const
{
	const float BaseBPM = bInCombat ? 110.0f : 60.0f;
	const float ScaledStress = FMath::Clamp(VeinCorruption, 0.0f, 1.0f) * 60.0f;
	return FMath::Clamp(BaseBPM + ScaledStress, 60.0f, 170.0f);
}
