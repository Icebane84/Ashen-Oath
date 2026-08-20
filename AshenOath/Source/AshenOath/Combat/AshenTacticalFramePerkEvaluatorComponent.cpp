// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTacticalFramePerkEvaluatorComponent.h"

UAshenTacticalFramePerkEvaluatorComponent::UAshenTacticalFramePerkEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTacticalFramePerkEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenTacticalFramePerkEvaluatorComponent::CalculateAdjustedSunPulseRadius(float BaseRadius, bool bHasEarnedKnowledge) const
{
	if (bHasEarnedKnowledge)
	{
		return BaseRadius * 1.35f; // +35% expanded hitbox
	}
	return BaseRadius;
}

float UAshenTacticalFramePerkEvaluatorComponent::GetGarrettCalloutTimeAdvance(bool bHasEarnedKnowledge) const
{
	return bHasEarnedKnowledge ? 1.0f : 0.0f; // 1.0s earlier callout
}
