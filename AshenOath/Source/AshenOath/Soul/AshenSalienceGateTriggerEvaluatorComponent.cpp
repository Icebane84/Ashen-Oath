// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Soul/AshenSalienceGateTriggerEvaluatorComponent.h"

UAshenSalienceGateTriggerEvaluatorComponent::UAshenSalienceGateTriggerEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenSalienceGateTriggerEvaluatorComponent::EvaluateSalienceTrigger(
	const FCanonicalSoulStateVector& OldState,
	const FCanonicalSoulStateVector& NewState,
	ESalienceTriggerClass& OutTriggerClass) const
{
	// 1. Lens Transmutation
	if (OldState.DominantLens != NewState.DominantLens)
	{
		OutTriggerClass = ESalienceTriggerClass::LensTransmutation;
		return true;
	}

	// 2. Debt Stage Escalation (crossing 0.50, 0.75, or 1.0)
	const bool bCrossed50 = (OldState.IntegrationDebt < 0.50f && NewState.IntegrationDebt >= 0.50f);
	const bool bCrossed75 = (OldState.IntegrationDebt < 0.75f && NewState.IntegrationDebt >= 0.75f);
	const bool bCrossed100 = (OldState.IntegrationDebt < 1.0f && NewState.IntegrationDebt >= 1.0f);

	if (bCrossed50 || bCrossed75 || bCrossed100)
	{
		OutTriggerClass = ESalienceTriggerClass::DebtStageEscalation;
		return true;
	}

	// 3. Relational Rupture (Dysregulation spike delta >= 0.15)
	if (FMath::Abs(NewState.AccumulatedDysregulation - OldState.AccumulatedDysregulation) >= 0.15f)
	{
		OutTriggerClass = ESalienceTriggerClass::RelationalRupture;
		return true;
	}

	return false;
}
