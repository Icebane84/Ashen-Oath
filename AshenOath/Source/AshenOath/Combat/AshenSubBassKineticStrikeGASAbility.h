// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenSubBassKineticStrikeGASAbility.generated.h"

/**
 * UAshenSubBassKineticStrikeGASAbility
 * 
 * Gameplay Ability generating heavy kinetic strikes with 30-60 Hz sub-bass audio transients.
 */
UCLASS()
class ASHENOATH_API UAshenSubBassKineticStrikeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSubBassKineticStrikeGASAbility();

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
	float SubBassPitchHertz = 45.0f;
};
