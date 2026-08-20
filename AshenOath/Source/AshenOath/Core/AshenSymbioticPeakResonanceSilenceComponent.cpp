// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 506: Ashen Symbiotic Peak Resonance Silence Component

#include "AshenSymbioticPeakResonanceSilenceComponent.h"

UAshenSymbioticPeakResonanceSilenceComponent::UAshenSymbioticPeakResonanceSilenceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsPeakResonanceActive = false;
	CalculatedLethalSilenceMultiplier = 1.0f;
}

void UAshenSymbioticPeakResonanceSilenceComponent::EvaluateResonanceSilence(float ActiveTrustScore, float ProximityDistance)
{
	const bool bWasActive = bIsPeakResonanceActive;
	bIsPeakResonanceActive = (ActiveTrustScore >= 90.0f) && (ProximityDistance <= 600.0f);
	CalculatedLethalSilenceMultiplier = bIsPeakResonanceActive ? 2.0f : 1.0f;

	if (bIsPeakResonanceActive != bWasActive)
	{
		OnResonanceSilenceTriggered.Broadcast(bIsPeakResonanceActive, CalculatedLethalSilenceMultiplier);

		UE_LOG(LogTemp, Warning, TEXT("UAshenSymbioticPeakResonanceSilenceComponent: PEAK RESONANCE LETHAL SILENCE -> %s (Tactical Barks Muted, Lethal Multiplier: %.1fx)."),
			bIsPeakResonanceActive ? TEXT("ACTIVE — PURE LETHAL SILENCE") : TEXT("INACTIVE"), CalculatedLethalSilenceMultiplier);
	}
}
