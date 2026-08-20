// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaBuffSpellPriorityEvaluatorComponent.h"

UAshenSerafinaBuffSpellPriorityEvaluatorComponent::UAshenSerafinaBuffSpellPriorityEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FName UAshenSerafinaBuffSpellPriorityEvaluatorComponent::EvaluateOptimalBuffSpell(float KaelenStaminaPct, int32 SurroundingEnemyCount, float SerafinaTrustInKaelen)
{
	if (KaelenStaminaPct < 0.3f && SerafinaTrustInKaelen >= 0.5f)
	{
		return FName("Spell_HasteAura");
	}
	else if (SurroundingEnemyCount >= 3)
	{
		return FName("Spell_WardingAegis");
	}
	return FName("Spell_MightEmpowerment");
}
