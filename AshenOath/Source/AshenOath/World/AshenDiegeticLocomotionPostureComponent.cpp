// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 474: Ashen Diegetic Locomotion Posture Component

#include "AshenDiegeticLocomotionPostureComponent.h"

UAshenDiegeticLocomotionPostureComponent::UAshenDiegeticLocomotionPostureComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CalculatedLimpBlend = 0.0f;
	CalculatedSpeedMultiplier = 1.0f;
}

void UAshenDiegeticLocomotionPostureComponent::UpdateLocomotionPosture(float CurrentHealth, float MaxHealth, float FatiguePercent)
{
	const float SafeMax = FMath::Max(1.0f, MaxHealth);
	const float HealthPercent = FMath::Clamp(CurrentHealth / SafeMax, 0.0f, 1.0f);

	CalculatedLimpBlend = FMath::Clamp(1.0f - HealthPercent, 0.0f, 1.0f);
	CalculatedSpeedMultiplier = FMath::Clamp(0.5f + (HealthPercent * 0.5f) - (FatiguePercent * 0.2f), 0.3f, 1.0f);

	OnPostureChanged.Broadcast(CalculatedLimpBlend, CalculatedSpeedMultiplier);

	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticLocomotionPostureComponent: LOCOMOTION POSTURE UPDATED — Limp Blend: %.2f | Speed Multiplier: %.2fx"),
		CalculatedLimpBlend, CalculatedSpeedMultiplier);
}
