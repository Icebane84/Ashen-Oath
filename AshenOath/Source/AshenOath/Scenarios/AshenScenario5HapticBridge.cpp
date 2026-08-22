// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario5HapticBridge.h"

UAshenScenario5HapticBridge::UAshenScenario5HapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenScenario5HapticBridge::EvaluateMireHaptics(
	EUnchainedVesselPhase Phase,
	bool bInDeepMud,
	float& OutTriggerResistance,
	float& OutHeartbeatPulseIntensity) const
{
	// Trigger resistance based on mud sludge viscosity
	OutTriggerResistance = bInDeepMud ? 0.75f : 0.15f;

	// Heartbeat pulse intensity based on Unchained phase
	switch (Phase)
	{
	case EUnchainedVesselPhase::UnchainedFrenzy:
		OutHeartbeatPulseIntensity = 0.95f; // Powerful 140 BPM pounding
		break;
	case EUnchainedVesselPhase::ExhaustedVulnerable:
		OutHeartbeatPulseIntensity = 0.40f; // Weak labored flutter
		break;
	case EUnchainedVesselPhase::Dormant:
	default:
		OutHeartbeatPulseIntensity = 0.10f; // Resting rhythm
		break;
	}
}
