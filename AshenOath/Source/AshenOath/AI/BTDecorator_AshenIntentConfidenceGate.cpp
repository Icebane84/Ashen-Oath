// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTDecorator_AshenIntentConfidenceGate.h"

UBTDecorator_AshenIntentConfidenceGate::UBTDecorator_AshenIntentConfidenceGate()
{
	NodeName = TEXT("Ashen Intent Confidence Gate");
	MinimumRequiredConfidence = EIntentConfidenceTier::Confident;
}

bool UBTDecorator_AshenIntentConfidenceGate::CalculateRawConditionValue(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory) const
{
	return true;
}
