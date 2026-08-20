// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenGEC_Transference.h"
#include "AshenAttributeSet.h"
#include "GameplayEffectExecutionCalculation.h"

UAshenGEC_Transference::UAshenGEC_Transference()
{
}

void UAshenGEC_Transference::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();

	// Snapshot incoming damage magnitude
	float UnmitigatedDamage = Spec.GetSetByCallerMagnitude(FGameplayTag::RequestGameplayTag(FName("Data.Damage")), false, 0.0f);
	if (UnmitigatedDamage <= 0.0f)
	{
		UnmitigatedDamage = 10.0f; // Default fallback damage
	}

	// Apply 25% Quiet Grace mitigation
	float MitigatedPain = UnmitigatedDamage * 0.75f;

	// Zero out original damage to prevent double-dipping on ally target
	OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UAshenAttributeSet::GetHealthAttribute(), EGameplayModOp::Additive, 0.0f));

	UE_LOG(LogTemp, Log, TEXT("UAshenGEC_Transference: Transferred %.1f raw damage to Serafina (Mitigated: %.1f). Target damage zeroed."), UnmitigatedDamage, MitigatedPain);
}
