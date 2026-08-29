// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenAlchemicalSlagTypes.h"
#include "AshenCampfireBladePolishBuffGASAbility.generated.h"

/**
 * UAshenCampfireBladePolishBuffGASAbility
 * 
 * Campfire Blade Polishing: Cleanses all soot from Oathbringer and applies the 5-minute Resolve Buff (+15% parry window).
 */
UCLASS()
class ASHENOATH_API UAshenCampfireBladePolishBuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCampfireBladePolishBuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|AlchemicalSlag")
	float ParryWindowBuffPercent = 0.15f;
};
