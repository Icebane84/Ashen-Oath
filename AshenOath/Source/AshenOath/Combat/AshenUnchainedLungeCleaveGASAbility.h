// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenUnchainedLungeCleaveGASAbility.generated.h"

/**
 * UAshenUnchainedLungeCleaveGASAbility
 * 
 * Gameplay Ability executing an explosive forward lunge strike that ignores mire mud penalties.
 */
UCLASS()
class ASHENOATH_API UAshenUnchainedLungeCleaveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenUnchainedLungeCleaveGASAbility();

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
	float LungeImpulseForce = 1200.0f;
};
