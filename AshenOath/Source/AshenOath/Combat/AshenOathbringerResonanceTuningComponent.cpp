// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 686: Ashen Oathbringer Resonance Tuning Component

#include "AshenOathbringerResonanceTuningComponent.h"

UAshenOathbringerResonanceTuningComponent::UAshenOathbringerResonanceTuningComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveUpgradeLevel = 1;
}

void UAshenOathbringerResonanceTuningComponent::ApplyResonanceTuning(int32 AdditionalUpgrades)
{
	ActiveUpgradeLevel = FMath::Clamp(ActiveUpgradeLevel + AdditionalUpgrades, 1, 10);
	const float AegisReflectionPower = ActiveUpgradeLevel * 25.0f;

	OnResonanceTuned.Broadcast(ActiveUpgradeLevel, AegisReflectionPower);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerResonanceTuningComponent: RESONANCE TUNING APPLIED -> Upgrade Level: %d | Aegis Reflection Power: %.1f."),
		ActiveUpgradeLevel, AegisReflectionPower);
}
