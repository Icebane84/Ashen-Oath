// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenApotheosisOverdriveBuffGASAbility.generated.h"

/**
 * UAshenApotheosisOverdriveBuffGASAbility
 * 
 * Unlocks 100% attack speed and removes stamina costs during sovereign apotheosis overdrive.
 */
UCLASS()
class ASHENOATH_API UAshenApotheosisOverdriveBuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenApotheosisOverdriveBuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Apotheosis")
	float AttackSpeedBonusPercent = 1.0f;
};
