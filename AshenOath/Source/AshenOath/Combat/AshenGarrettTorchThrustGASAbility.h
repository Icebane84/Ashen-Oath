// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenGarrettTorchThrustGASAbility.generated.h"

/**
 * UAshenGarrettTorchThrustGASAbility
 * 
 * Garrett thrusts his kindle torch forward, staggering frost enemies and creating a temporary heat flare.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettTorchThrustGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettTorchThrustGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Garrett")
	float TorchHeatDamageBonus = 30.0f;
};
