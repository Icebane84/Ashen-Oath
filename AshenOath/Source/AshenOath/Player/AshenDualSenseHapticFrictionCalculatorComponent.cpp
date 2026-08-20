// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Player/AshenDualSenseHapticFrictionCalculatorComponent.h"

UAshenDualSenseHapticFrictionCalculatorComponent::UAshenDualSenseHapticFrictionCalculatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDualSenseHapticFrictionCalculatorComponent::BeginPlay() { Super::BeginPlay(); }

FHapticFrictionProfile UAshenDualSenseHapticFrictionCalculatorComponent::ComputeHapticFriction(float KaelenCorruption, float SerafinaBurnout, float ExecutionProgress) const
{
	FHapticFrictionProfile Profile;

	// Trigger resistance scales from 180 to 255 based on ExecutionProgress
	const int32 DynamicResistance = 180 + FMath::RoundToInt(FMath::Clamp(ExecutionProgress, 0.0f, 1.0f) * 75.0f);
	Profile.TriggerResistance = FMath::Clamp(DynamicResistance, 180, 255);

	// Left Frequency (Shadow Mark): 20 to 40 Hz modulated by KaelenCorruption
	Profile.LeftFrequencyHz = 20.0f + (FMath::Clamp(KaelenCorruption, 0.0f, 1.0f) * 20.0f);

	// Right Frequency (White Flame): 150 to 200 Hz modulated by SerafinaBurnout
	Profile.RightFrequencyHz = 150.0f + (FMath::Clamp(SerafinaBurnout, 0.0f, 1.0f) * 50.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenDualSenseHapticFrictionCalculatorComponent: Haptic Friction -> Resistance: %d, Left: %.1fHz, Right: %.1fHz"),
		Profile.TriggerResistance, Profile.LeftFrequencyHz, Profile.RightFrequencyHz);

	return Profile;
}
