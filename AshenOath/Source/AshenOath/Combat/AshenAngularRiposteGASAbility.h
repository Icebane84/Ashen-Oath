// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenAngularRiposteGASAbility.generated.h"

/**
 * UAshenAngularRiposteGASAbility
 * 
 * Gameplay Ability executing mirrored angular ripostes with +35% kinetic counter damage.
 */
UCLASS()
class ASHENOATH_API UAshenAngularRiposteGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenAngularRiposteGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|KineticBerserk|GAS")
	float CounterDamageMultiplier = 1.35f;
};
