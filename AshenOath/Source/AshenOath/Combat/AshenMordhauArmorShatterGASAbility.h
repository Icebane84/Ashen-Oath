// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenMordhauArmorShatterGASAbility.generated.h"

/**
 * UAshenMordhauArmorShatterGASAbility
 * 
 * Mordhau / Half-Sword Execution: Armored gauntlet blade grip or inverted pommel bludgeon, dealing 100% true physical armor penetration and +75% shield posture shatter.
 */
UCLASS()
class ASHENOATH_API UAshenMordhauArmorShatterGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMordhauArmorShatterGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Oathbringer")
	float ArmorPenetration = 1.00f;
};
