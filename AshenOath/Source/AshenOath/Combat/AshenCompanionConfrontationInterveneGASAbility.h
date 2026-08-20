// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "AshenCompanionConfrontationInterveneGASAbility.generated.h"

/**
 * UAshenCompanionConfrontationInterveneGASAbility
 * 
 * GAS ability triggered when high-trust companion physically steps in to body-block
 * Kaelen from succumbing to suicidal Ashen Mark rage.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionConfrontationInterveneGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCompanionConfrontationInterveneGASAbility();

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

	/** Executes physical body-blocking stop */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Intervention")
	bool TriggerBodyBlockIntervention(AActor* TargetPlayerActor);
};
