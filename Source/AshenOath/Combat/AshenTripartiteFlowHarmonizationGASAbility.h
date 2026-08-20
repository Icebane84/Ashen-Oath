// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenTripartiteFlowHarmonizationGASAbility.generated.h"

/**
 * UAshenTripartiteFlowHarmonizationGASAbility
 * 
 * Activates during High Flow / Synchronized Resonance (Psi >= 0.75), granting party hyper-poise,
 * accelerating stamina regeneration, and priming Tripartite Sync Finishers.
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteFlowHarmonizationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTripartiteFlowHarmonizationGASAbility();

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

	/** Executes the primed sync finisher */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Tripartite")
	bool ExecuteHarmonizedSyncFinisher(ESyncFinisherType FinisherType);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Tripartite")
	float FlowHarmonizationDuration = 8.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Tripartite")
	float PartyHyperPoiseMultiplier = 2.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Tripartite")
	float StaminaRegenBonusMultiplier = 1.40f;
};
