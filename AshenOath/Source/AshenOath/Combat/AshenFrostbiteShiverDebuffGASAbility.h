// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenFrostbiteShiverDebuffGASAbility.generated.h"

/**
 * UAshenFrostbiteShiverDebuffGASAbility
 * 
 * Applies physiological frostbite penalties, slowing movement speed and inducing somatic shivers.
 */
UCLASS()
class ASHENOATH_API UAshenFrostbiteShiverDebuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenFrostbiteShiverDebuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Debuff")
	float MaxSpeedReductionPercent = 0.60f;
};
