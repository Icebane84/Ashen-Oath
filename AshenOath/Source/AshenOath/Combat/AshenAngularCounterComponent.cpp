// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenAngularCounterComponent.h"

UAshenAngularCounterComponent::UAshenAngularCounterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenAngularCounterComponent::CalculateCounterAngle(
	const FVector& ForwardVector,
	const FVector& IncomingVector) const
{
	const FVector NormFwd = ForwardVector.GetSafeNormal2D();
	const FVector NormInc = IncomingVector.GetSafeNormal2D();

	const float Dot = FVector::DotProduct(NormFwd, NormInc);
	const float Cross = FVector::CrossProduct(NormFwd, NormInc).Z;

	float AngleRad = FMath::Atan2(Cross, Dot);
	float AngleDeg = FMath::RadiansToDegrees(AngleRad);

	if (AngleDeg < 0.0f)
	{
		AngleDeg += 360.0f;
	}

	return AngleDeg;
}
