// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenMireMudWadeGASAbility.generated.h"

/**
 * UAshenMireMudWadeGASAbility
 * 
 * Environmental ability applying mud friction slowdown and heavy stamina drain.
 */
UCLASS()
class ASHENOATH_API UAshenMireMudWadeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMireMudWadeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario5|GAS")
	float MudSpeedScale = 0.50f;
};
