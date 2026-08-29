// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenSigilResonanceEvaluator.h"

UAshenSigilResonanceEvaluator::UAshenSigilResonanceEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenSigilResonanceEvaluator::EvaluateHybridFinisherDamage(
	ESigilResonanceEffect SigilA,
	ESigilResonanceEffect SigilB) const
{
	if (CanTriggerResonance(SigilA, SigilB))
	{
		return 1.40f; // +40% bonus hybrid finisher damage
	}
	return 1.00f;
}

bool UAshenSigilResonanceEvaluator::CanTriggerResonance(
	ESigilResonanceEffect SigilA,
	ESigilResonanceEffect SigilB) const
{
	return (SigilA != ESigilResonanceEffect::None && SigilB != ESigilResonanceEffect::None && SigilA != SigilB);
}
