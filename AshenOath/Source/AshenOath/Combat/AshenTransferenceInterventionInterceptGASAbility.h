// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenTransferenceInterventionInterceptGASAbility.generated.h"

/**
 * UAshenTransferenceInterventionInterceptGASAbility
 * 
 * Kaelen intervention ability: Intercepts a lethal boss attack on a companion,
 * absorbing the blow and forging deep trust (+0.20 Trust).
 */
UCLASS()
class ASHENOATH_API UAshenTransferenceInterventionInterceptGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTransferenceInterventionInterceptGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Intervention")
	float TrustRewardScalar = 0.20f;
};
