// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenMagmaSurgeEruptionGASAbility.generated.h"

/**
 * UAshenMagmaSurgeEruptionGASAbility
 * 
 * Environmental hazard ability dealing 150 Heat damage/s to all units caught in the active eruption zone.
 */
UCLASS()
class ASHENOATH_API UAshenMagmaSurgeEruptionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMagmaSurgeEruptionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Magma")
	float MagmaDamagePerSecond = 150.0f;
};
