// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenMasterCutTypes.h"
#include "Combat/AbilityTask_EvaluateMontageFlowPosition.h"
#include "AshenGameplayAbility_CombatStrike.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStrikeFlowGlintResolved, EAshenFlowTimingResult, Classification, float, EffectiveStaminaCost);

/**
 * UAshenGameplayAbility_CombatStrike
 *
 * Authoritative base gameplay ability for all historical greatsword strikes.
 * Couples with UAbilityTask_EvaluateMontageFlowPosition for hit-stop-immune Flow Glint timing,
 * manages 0-stamina refunds on Perfect timing, and transitions Liechtenauer guard tags.
 * (PATCH v158.18.0 / CONVERGENCE-SPEC-101 / PRS-001-SPEC-COMBAT-104)
 */
UCLASS(Abstract)
class ASHENOATH_API UAshenGameplayAbility_CombatStrike : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGameplayAbility_CombatStrike();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility,
		bool bWasCancelled) override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Combat")
	const FAshenStrikeParameters& GetStrikeParameters() const { return StrikeParams; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Combat")
	FOnStrikeFlowGlintResolved OnStrikeFlowGlintResolved;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat")
	FAshenStrikeParameters StrikeParams;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat")
	TObjectPtr<UAnimMontage> StrikeMontage;

	UFUNCTION()
	virtual void HandleFlowTimingResolved(EAshenFlowTimingResult Result);

	UPROPERTY()
	TObjectPtr<UAbilityTask_EvaluateMontageFlowPosition> FlowEvalTask;
};
