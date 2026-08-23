// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenAvoidantMercyDiagnosisEvaluator.h"

UAshenAvoidantMercyDiagnosisEvaluator::UAshenAvoidantMercyDiagnosisEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

EWaystationRunMode UAshenAvoidantMercyDiagnosisEvaluator::DiagnoseSparingAction(float IntegrationDebt) const
{
	// High Integration Debt (>= 0.75) converts the interpretation to Avoidant Mercy (Dissociation)
	if (IntegrationDebt >= 0.75f)
	{
		return EWaystationRunMode::RunD_AvoidantMercy;
	}

	return EWaystationRunMode::RunB_PureGrace;
}
