// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettStateTreeFormationEvaluator.h"

UAshenGarrettStateTreeFormationEvaluator::UAshenGarrettStateTreeFormationEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenGarrettStateTreeFormationEvaluator::CalculateFormationRadius(float GarrettTrust) const
{
	float FormationRadius = FMath::Lerp(800.0f, 300.0f, FMath::Clamp(GarrettTrust, 0.0f, 1.0f));
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettStateTreeFormationEvaluator: Calculated formation radius %.1f for trust %.2f"), FormationRadius, GarrettTrust);
	return FormationRadius;
}
