// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Companions/AshenShadowOveruseAuditorComponent.h"

UAshenShadowOveruseAuditorComponent::UAshenShadowOveruseAuditorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CombatCorruptionTotal = 0.0f;
}

EShadowMarkOveruseResponse UAshenShadowOveruseAuditorComponent::AuditShadowUsage(float CorruptionCost)
{
	CombatCorruptionTotal += CorruptionCost;

	if (CombatCorruptionTotal >= 0.70f)
	{
		return EShadowMarkOveruseResponse::PhysicalIntervention;
	}
	if (CombatCorruptionTotal >= 0.35f)
	{
		return EShadowMarkOveruseResponse::VerbalCaution;
	}

	return EShadowMarkOveruseResponse::PermittedRestraint;
}
