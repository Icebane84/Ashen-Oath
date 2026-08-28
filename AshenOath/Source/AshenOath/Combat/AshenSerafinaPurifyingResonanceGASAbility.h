// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenSerafinaPurifyingResonanceGASAbility.generated.h"

/**
 * UAshenSerafinaPurifyingResonanceGASAbility
 * 
 * Serafina channels radiant White Flame acoustic resonance, restoring +30 sanity and aligning Quartz stems.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaPurifyingResonanceGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaPurifyingResonanceGASAbility();

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
	float SanityRestored = 30.0f;
};
