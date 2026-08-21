// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Haptics/AshenDirectionalTactileTickComponent.h"

UAshenDirectionalTactileTickComponent::UAshenDirectionalTactileTickComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDirectionalTactileTickComponent::CalculateDirectionalTicks(
	const FVector& PlayerForward,
	const FVector& ThreatDirection,
	float ThreatIntensity,
	float& OutLeftMotor,
	float& OutRightMotor) const
{
	const FVector NormForward = PlayerForward.GetSafeNormal2D();
	const FVector NormThreat = ThreatDirection.GetSafeNormal2D();

	// Cross product Z indicates left (-1) vs right (+1)
	const float CrossZ = FVector::CrossProduct(NormForward, NormThreat).Z;
	const float Dot = FVector::DotProduct(NormForward, NormThreat);

	const float BaseIntensity = FMath::Clamp(ThreatIntensity, 0.0f, 1.0f);

	if (CrossZ < -0.1f)
	{
		// Threat on Left
		OutLeftMotor = BaseIntensity;
		OutRightMotor = BaseIntensity * 0.2f;
	}
	else if (CrossZ > 0.1f)
	{
		// Threat on Right
		OutLeftMotor = BaseIntensity * 0.2f;
		OutRightMotor = BaseIntensity;
	}
	else
	{
		// Center / Forward / Rear
		OutLeftMotor = BaseIntensity * 0.6f;
		OutRightMotor = BaseIntensity * 0.6f;
	}
}
