// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenEarnedKnowledgeGASAbility.h"

UAshenEarnedKnowledgeGASAbility::UAshenEarnedKnowledgeGASAbility()
{
	StaggerBonusMultiplier = 1.20f;
	DefenseBonusMultiplier = 0.85f;
}

float UAshenEarnedKnowledgeGASAbility::EvaluateStaggerDamage(float BaseStagger, bool bHasEarnedKnowledge) const
{
	if (bHasEarnedKnowledge)
	{
		return BaseStagger * StaggerBonusMultiplier;
	}
	return BaseStagger;
}
