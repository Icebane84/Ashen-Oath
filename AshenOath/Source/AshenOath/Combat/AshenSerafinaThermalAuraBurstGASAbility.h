// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenSerafinaThermalAuraBurstGASAbility.generated.h"

/**
 * UAshenSerafinaThermalAuraBurstGASAbility
 * 
 * Serafina unleashes a radiant thermal pulse that instantly purges 0.40 frostbite from all nearby allies.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaThermalAuraBurstGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaThermalAuraBurstGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Serafina")
	float FrostbitePurgeAmount = 0.40f;
};
