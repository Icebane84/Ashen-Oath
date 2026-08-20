// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 762: Ashen Malakor Phase Transition Ability

#include "AshenMalakorPhaseTransitionAbility.h"

void UAshenMalakorPhaseTransitionAbility::TriggerPhaseTransition(int32 TargetPhase)
{
	const float SpeedMult = (TargetPhase >= 2) ? 1.5f : 1.0f;
	OnPhaseTransitionExecuted.Broadcast(TargetPhase, SpeedMult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenMalakorPhaseTransitionAbility: PHASE TRANSITION TRIGGERED -> New Boss Phase: %d | Attack Speed Multiplier: %.2fx."),
		TargetPhase, SpeedMult);
}
