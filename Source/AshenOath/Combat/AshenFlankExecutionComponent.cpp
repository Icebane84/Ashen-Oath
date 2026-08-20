// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenFlankExecutionComponent.h"

UAshenFlankExecutionComponent::UAshenFlankExecutionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxFlankAngleDegrees = 45.0f;
	FlankDamageMultiplier = 2.0f;
}
void UAshenFlankExecutionComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenFlankExecutionComponent::IsFlankingEnemy(const FVector& AttackerLocation, const FVector& EnemyLocation, const FVector& EnemyForwardVector, float& OutAngleDegrees) const
{
	FVector DirToAttacker = (AttackerLocation - EnemyLocation).GetSafeNormal2D();
	FVector RearVector = -EnemyForwardVector.GetSafeNormal2D();

	const float Dot = FVector::DotProduct(DirToAttacker, RearVector);
	const float AngleRadians = FMath::Acos(FMath::Clamp(Dot, -1.0f, 1.0f));
	OutAngleDegrees = FMath::RadiansToDegrees(AngleRadians);

	const bool bFlanking = OutAngleDegrees <= MaxFlankAngleDegrees;
	return bFlanking;
}

float UAshenFlankExecutionComponent::CalculateFlankDamage(float BaseDamage, bool bIsFlanking) const
{
	const float FinalDamage = bIsFlanking ? (BaseDamage * FlankDamageMultiplier) : BaseDamage;
	return FinalDamage;
}
