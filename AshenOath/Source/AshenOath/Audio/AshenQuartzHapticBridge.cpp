// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenQuartzHapticBridge.h"

UAshenQuartzHapticBridge::UAshenQuartzHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenQuartzHapticBridge::EvaluateQuartzHaptics(
	ECombatFlowState FlowState,
	EAlchemicalAudioFilter ActiveFilter,
	float& OutRhythmPulseGain,
	float& OutTackleImpactRumble,
	float& OutFlowStateHarmonicVibe)
{
	// 115 BPM rhythm pulse baseline
	OutRhythmPulseGain = (FlowState == ECombatFlowState::SymbioticResonance) ? 0.85f : 0.35f;

	// Physical tackle impact rumble
	OutTackleImpactRumble = (ActiveFilter == EAlchemicalAudioFilter::TackleSideChain) ? 0.95f : 0.0f;

	// Flow state harmonic vibration
	OutFlowStateHarmonicVibe = (FlowState == ECombatFlowState::SymbioticResonance) ? 0.60f : 0.0f;
}
