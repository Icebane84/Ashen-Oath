// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 822: Ashen DualSense Adaptive Trigger Haptic Friction Component

#include "AshenDualSenseAdaptiveTriggerHapticFrictionComponent.h"

UAshenDualSenseAdaptiveTriggerHapticFrictionComponent::UAshenDualSenseAdaptiveTriggerHapticFrictionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ResistanceThreshold = 0.85f;
}

bool UAshenDualSenseAdaptiveTriggerHapticFrictionComponent::EvaluateTriggerPressPastThreshold(float AppliedForceNormalized)
{
	const bool bBroken = (AppliedForceNormalized >= ResistanceThreshold);
	OnTriggerResistanceUpdated.Broadcast(ResistanceThreshold, bBroken);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDualSenseAdaptiveTriggerHapticFrictionComponent: ADAPTIVE TRIGGER THRESHOLD EVALUATED -> Force: %.2f / %.2f | Threshold Broken: %s."),
		AppliedForceNormalized, ResistanceThreshold, bBroken ? TEXT("TRUE (SURRENDER EXECUTED)") : TEXT("FALSE (RESISTING)"));

	return bBroken;
}
