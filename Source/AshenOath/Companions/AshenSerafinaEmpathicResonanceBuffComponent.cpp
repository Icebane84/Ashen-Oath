// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 722: Ashen Serafina Empathic Resonance Buff Component

#include "AshenSerafinaEmpathicResonanceBuffComponent.h"

UAshenSerafinaEmpathicResonanceBuffComponent::UAshenSerafinaEmpathicResonanceBuffComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActivePostureRecoveryBonus = 25.0f;
}

float UAshenSerafinaEmpathicResonanceBuffComponent::EvaluateEmpathicResonanceBuff(float SerafinaCurrentHealthPercent)
{
	const bool bUninjured = (SerafinaCurrentHealthPercent >= 80.0f);
	ActivePostureRecoveryBonus = bUninjured ? 25.0f : 10.0f;

	OnResonanceBuffApplied.Broadcast(ActivePostureRecoveryBonus, bUninjured);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaEmpathicResonanceBuffComponent: EMPATHIC RESONANCE BUFF EVALUATED -> Health: %.1f%% | Posture Recovery Bonus: +%.0f%% (Uninjured: %s)."),
		SerafinaCurrentHealthPercent, ActivePostureRecoveryBonus, bUninjured ? TEXT("TRUE") : TEXT("FALSE"));

	return ActivePostureRecoveryBonus;
}
