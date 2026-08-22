// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario5WeepingMireTypes.h"
#include "AshenGarrettBoundaryDefenseGASAbility.generated.h"

/**
 * UAshenGarrettBoundaryDefenseGASAbility
 * 
 * Gameplay Ability directing Garrett to form a protective perimeter around Kaelen during post-frenzy exhaustion.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettBoundaryDefenseGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettBoundaryDefenseGASAbility();

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
	float DefenseRadiusCentimeters = 400.0f;
};
