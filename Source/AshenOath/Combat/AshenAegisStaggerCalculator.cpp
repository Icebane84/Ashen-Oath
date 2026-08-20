// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 676: Ashen Aegis Stagger Calculator

#include "AshenAegisStaggerCalculator.h"

float UAshenAegisStaggerCalculator::CalculateGlancingStaggerImpact(float EnemyIncomingMass, float DeflectionAngleDegrees)
{
	const float AngleEfficiency = FMath::Cos(FMath::DegreesToRadians(DeflectionAngleDegrees));
	LastCalculatedStaggerImpact = FMath::Clamp(EnemyIncomingMass * 1.8f * AngleEfficiency, 50.0f, 500.0f);
	const bool bKnockback = (LastCalculatedStaggerImpact > 250.0f);

	OnStaggerCalculated.Broadcast(LastCalculatedStaggerImpact, bKnockback);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAegisStaggerCalculator: GLANCING STAGGER CALCULATED -> Mass: %.1f | Angle: %.1f deg | Impact: %.1f | Knockback: %s."),
		EnemyIncomingMass, DeflectionAngleDegrees, LastCalculatedStaggerImpact, bKnockback ? TEXT("TRUE") : TEXT("FALSE"));

	return LastCalculatedStaggerImpact;
}
