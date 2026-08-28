// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenSanityCollapseDissonanceGASAbility.generated.h"

/**
 * UAshenSanityCollapseDissonanceGASAbility
 * 
 * Debuff state triggered at critical sanity (<25), narrowing parry timing windows by -35% and amplifying dodge stamina costs by 1.5x.
 */
UCLASS()
class ASHENOATH_API UAshenSanityCollapseDissonanceGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSanityCollapseDissonanceGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Convergence")
	float ParryWindowReduction = 0.35f;
};
