// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenGarrettEcholocationTapGASAbility.generated.h"

/**
 * UAshenGarrettEcholocationTapGASAbility
 * 
 * Garrett taps his twin blades together rhythmically, emitting a 900uu sonic ping that marks lurking enemies in shadows.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettEcholocationTapGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettEcholocationTapGASAbility();

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
	float TapPingRadiusUU = 900.0f;
};
