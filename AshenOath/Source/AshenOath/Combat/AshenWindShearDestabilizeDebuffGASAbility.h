// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenWindShearDestabilizeDebuffGASAbility.generated.h"

/**
 * UAshenWindShearDestabilizeDebuffGASAbility
 * 
 * Environmental debuff applied during high-altitude gales, imposing airborne drift and jump aim inaccuracy.
 */
UCLASS()
class ASHENOATH_API UAshenWindShearDestabilizeDebuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenWindShearDestabilizeDebuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Wind")
	float MaxDestabilizationPenalty = 0.75f;
};
