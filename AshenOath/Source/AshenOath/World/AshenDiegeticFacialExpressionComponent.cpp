// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 501: Ashen Diegetic Facial Expression Component

#include "AshenDiegeticFacialExpressionComponent.h"

UAshenDiegeticFacialExpressionComponent::UAshenDiegeticFacialExpressionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CalculatedPainGrimaceWeight = 0.0f;
	CalculatedExhaustionWeight = 0.0f;
}

void UAshenDiegeticFacialExpressionComponent::UpdateFacialMorphWeights(float CurrentHealth, float MaxHealth, float FatiguePercent)
{
	const float SafeMax = FMath::Max(1.0f, MaxHealth);
	CalculatedPainGrimaceWeight = FMath::Clamp(1.0f - (CurrentHealth / SafeMax), 0.0f, 1.0f);
	CalculatedExhaustionWeight = FMath::Clamp(FatiguePercent, 0.0f, 1.0f);

	OnFacialExpressionUpdated.Broadcast(CalculatedPainGrimaceWeight, CalculatedExhaustionWeight);

	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticFacialExpressionComponent: FACIAL MORPH WEIGHTS — Pain: %.2f | Exhaustion: %.2f"),
		CalculatedPainGrimaceWeight, CalculatedExhaustionWeight);
}
