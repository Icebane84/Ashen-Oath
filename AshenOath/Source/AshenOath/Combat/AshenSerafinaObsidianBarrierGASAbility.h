// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenSerafinaObsidianBarrierGASAbility.generated.h"

/**
 * UAshenSerafinaObsidianBarrierGASAbility
 * 
 * Serafina creates an Obsidian Thermal Barrier deflecting lava projectiles and absorbing volcanic heat.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaObsidianBarrierGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaObsidianBarrierGASAbility();

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
	float BarrierAbsorptionJoules = 5000.0f;
};
