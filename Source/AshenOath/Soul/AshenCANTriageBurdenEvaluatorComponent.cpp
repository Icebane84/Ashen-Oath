// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 642: Ashen CAN Triage Burden Evaluator Component

#include "AshenCANTriageBurdenEvaluatorComponent.h"

UAshenCANTriageBurdenEvaluatorComponent::UAshenCANTriageBurdenEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveTriageWeight = 0.0f;
}

void UAshenCANTriageBurdenEvaluatorComponent::EvaluateTriageBurden(float DeltaTriageWeight)
{
	ActiveTriageWeight = FMath::Clamp(ActiveTriageWeight + DeltaTriageWeight, 0.0f, 100.0f);
	const float SacrificeCost = ActiveTriageWeight * 0.4f;

	OnTriageBurdenEvaluated.Broadcast(ActiveTriageWeight, SacrificeCost);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCANTriageBurdenEvaluatorComponent: TRIAGE BURDEN EVALUATED -> Weight: %.1f | Sacrifice Cost: %.1f (can-triage_burden)."),
		ActiveTriageWeight, SacrificeCost);
}
