// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenCampfireCookingTypes.h"
#include "AshenKaelenVenisonCarveGASAbility.generated.h"

/**
 * UAshenKaelenVenisonCarveGASAbility
 * 
 * Kaelen uses the sharp edge of Oathbringer to field-dress Gloomwood game, yielding +20% extra culinary rations.
 */
UCLASS()
class ASHENOATH_API UAshenKaelenVenisonCarveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenKaelenVenisonCarveGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Cooking")
	float RationHarvestYieldBonus = 0.20f;
};
