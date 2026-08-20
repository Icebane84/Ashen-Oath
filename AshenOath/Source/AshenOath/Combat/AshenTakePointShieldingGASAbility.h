// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenTakePointShieldingGASAbility.generated.h"

/**
 * UAshenTakePointShieldingGASAbility
 * 
 * Companion ability taking point ahead of Kaelen ($200\text{--}300\text{uu}$ forward offset)
 * to shield him during cognitive crises.
 */
UCLASS()
class ASHENOATH_API UAshenTakePointShieldingGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTakePointShieldingGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Vanguard")
	float ForwardLeadDistanceUU = 250.0f;
};
