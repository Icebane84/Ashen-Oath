// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenHeavyCleaveDemolitionGASAbility.generated.h"

/**
 * UAshenHeavyCleaveDemolitionGASAbility
 * 
 * Kaelen executes a downward heavy cleave using the living nightsteel blade, shattering stone boulders and clearing navmesh choke points.
 */
UCLASS()
class ASHENOATH_API UAshenHeavyCleaveDemolitionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenHeavyCleaveDemolitionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Demolition")
	float CleaveAppliedForce = 500.0f;
};
