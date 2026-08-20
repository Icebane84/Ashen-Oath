// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 699: Ashen CAN Pragmatic Adaptation Evaluator

#include "AshenCANPragmaticAdaptationEvaluator.h"

UAshenCANPragmaticAdaptationEvaluator::UAshenCANPragmaticAdaptationEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActivePragmatismWeight = 0.5f;
}

void UAshenCANPragmaticAdaptationEvaluator::EvaluatePragmaticAdaptation(float TacticalNecessityWeight)
{
	ActivePragmatismWeight = FMath::Clamp(TacticalNecessityWeight, 0.0f, 1.0f);
	const float Multiplier = 1.0f + (ActivePragmatismWeight * 0.4f); // Up to +40% utility bonus

	OnAdaptationEvaluated.Broadcast(ActivePragmatismWeight, Multiplier);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCANPragmaticAdaptationEvaluator: CAN-PRAGMATIC_ADAPTATION EVALUATED -> Pragmatism Weight: %.2f | Utility Multiplier: %.2fx."),
		ActivePragmatismWeight, Multiplier);
}
