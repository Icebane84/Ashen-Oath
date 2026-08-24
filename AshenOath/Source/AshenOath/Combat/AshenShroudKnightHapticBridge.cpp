// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenShroudKnightHapticBridge.h"

UAshenShroudKnightHapticBridge::UAshenShroudKnightHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenShroudKnightHapticBridge::EvaluateBossHaptics(
	EShroudKnightPhaseState PhaseState,
	float Infection01,
	ETrinityStrikeStep TrinityStep,
	float& OutTriggerResistance,
	float& OutParanoiaJitterRumble,
	float& OutFinisherImpactGain)
{
	// Trigger resistance (Free/slack in spectral phasing, firm in physical)
	OutTriggerResistance = (PhaseState == EShroudKnightPhaseState::SpectralPhasing) ? 0.05f : 0.70f;

	// Paranoia jitter rumble
	OutParanoiaJitterRumble = FMath::Clamp(Infection01 * 0.80f, 0.0f, 0.80f);

	// Trinity Strike finisher burst
	OutFinisherImpactGain = (TrinityStep == ETrinityStrikeStep::SerafinaPurgeBeam) ? 1.00f : 0.0f;
}
