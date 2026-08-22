// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenKineticBerserkTypes.h"
#include "AshenPlanarDebrisShearGASAbility.generated.h"

/**
 * UAshenPlanarDebrisShearGASAbility
 * 
 * Gameplay Ability executing planar cutting through masonry with Niagara back-face dust ejection.
 */
UCLASS()
class ASHENOATH_API UAshenPlanarDebrisShearGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPlanarDebrisShearGASAbility();

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
	float StructuralStrainJoules = 5200.0f;
};
