// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaSynergyShieldSpellEvaluatorComponent.h"

UAshenSerafinaSynergyShieldSpellEvaluatorComponent::UAshenSerafinaSynergyShieldSpellEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaSynergyShieldSpellEvaluatorComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	SerafinaTrustLevel = NewState.SerafinaTrust;
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaSynergyShieldSpellEvaluatorComponent: Serafina trust level set to %.2f"), SerafinaTrustLevel);
}

FName UAshenSerafinaSynergyShieldSpellEvaluatorComponent::SelectBarrierSpell(float PartyHealthPercent) const
{
	if (PartyHealthPercent < 0.3f && SerafinaTrustLevel > 0.7f)
	{
		return FName("Spell_PrismaticAegis");
	}
	return FName("Spell_BasicWardingWard");
}
