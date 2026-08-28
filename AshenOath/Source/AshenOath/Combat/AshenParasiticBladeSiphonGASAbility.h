// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenParasiticBladeSiphonGASAbility.generated.h"

/**
 * UAshenParasiticBladeSiphonGASAbility
 * 
 * Siphons vital essence on heavy greatsword cleaves, reducing blade hunger by -30% and stabilizing wielder sanity.
 */
UCLASS()
class ASHENOATH_API UAshenParasiticBladeSiphonGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenParasiticBladeSiphonGASAbility();

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
	float HungerSatedAmount01 = 0.30f;
};
