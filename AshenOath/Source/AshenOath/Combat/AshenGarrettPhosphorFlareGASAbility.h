// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario2SentinelsGambitTypes.h"
#include "AshenGarrettPhosphorFlareGASAbility.generated.h"

/**
 * UAshenGarrettPhosphorFlareGASAbility
 * 
 * Gameplay Ability launching a blinding White Flame phosphor flare into vault chambers.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettPhosphorFlareGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettPhosphorFlareGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario2|GAS")
	float BlindDurationSeconds = 5.0f;
};
