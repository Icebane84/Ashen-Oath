// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenVomTagOverheadCleaveGASAbility.generated.h"

/**
 * UAshenVomTagOverheadCleaveGASAbility
 * 
 * Vom Tag Guard Execution: Executes a heavy downward vertical cleave with hyper-armor, dealing +40% posture damage and igniting crimson fuller embers.
 */
UCLASS()
class ASHENOATH_API UAshenVomTagOverheadCleaveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenVomTagOverheadCleaveGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Oathbringer")
	float PoiseDamageMultiplier = 1.40f;
};
