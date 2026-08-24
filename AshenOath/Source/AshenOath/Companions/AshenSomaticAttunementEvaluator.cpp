// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenSomaticAttunementEvaluator.h"

UAshenSomaticAttunementEvaluator::UAshenSomaticAttunementEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenSomaticAttunementEvaluator::EvaluateFinisherDamageMultiplier(float AttunementScore) const
{
	const float Clamped = FMath::Clamp(AttunementScore, 0.0f, 1.0f);
	return 1.0f + (Clamped * 2.0f); // 1.0x to 3.0x
}

ECompanionAttunementPhase UAshenSomaticAttunementEvaluator::ClassifyAttunementPhase(float AttunementScore) const
{
	if (AttunementScore >= 0.70f)
	{
		return ECompanionAttunementPhase::UnifiedResonance;
	}
	else if (AttunementScore < 0.30f)
	{
		return ECompanionAttunementPhase::FracturedDivergence;
	}

	return ECompanionAttunementPhase::GuardedAlignment;
}
