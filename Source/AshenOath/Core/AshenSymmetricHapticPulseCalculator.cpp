// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 832: Ashen Symmetric Haptic Pulse Calculator

#include "AshenSymmetricHapticPulseCalculator.h"

void UAshenSymmetricHapticPulseCalculator::CalculateAsymmetricHapticPulses(float CorruptionLevel, float PanicBPM)
{
	const float LeftThrum = FMath::Clamp(CorruptionLevel * 0.8f, 20.0f, 100.0f); // Low chaotic thrum
	const float RightPanic = FMath::Clamp(PanicBPM * 0.75f, 50.0f, 150.0f);      // Tight rapid pulse

	OnHapticsCalculated.Broadcast(LeftThrum, RightPanic);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSymmetricHapticPulseCalculator: ASYMMETRIC HAPTICS CALCULATED -> Left Corruption Thrum: %.1f Hz | Right Panic Pulse: %.1f Hz."),
		LeftThrum, RightPanic);
}
