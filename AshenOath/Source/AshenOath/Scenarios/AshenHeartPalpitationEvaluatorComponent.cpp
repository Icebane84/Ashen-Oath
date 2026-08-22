// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenHeartPalpitationEvaluatorComponent.h"

UAshenHeartPalpitationEvaluatorComponent::UAshenHeartPalpitationEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenHeartPalpitationEvaluatorComponent::EvaluateHeartRateBPM(
	EUnchainedVesselPhase Phase,
	float StressPercent) const
{
	switch (Phase)
	{
	case EUnchainedVesselPhase::UnchainedFrenzy:
		// Heavy tachycardia: 130 to 170 BPM based on stress
		return 130.0f + (FMath::Clamp(StressPercent, 0.0f, 1.0f) * 40.0f);
	case EUnchainedVesselPhase::ExhaustedVulnerable:
		// Slow labored pulse: 100 to 115 BPM
		return 100.0f + (FMath::Clamp(StressPercent, 0.0f, 1.0f) * 15.0f);
	case EUnchainedVesselPhase::Dormant:
	default:
		// Resting combat pulse: 75 to 95 BPM
		return 75.0f + (FMath::Clamp(StressPercent, 0.0f, 1.0f) * 20.0f);
	}
}
