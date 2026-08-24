// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenBladeWipeCampfireGASAbility.generated.h"

/**
 * UAshenBladeWipeCampfireGASAbility
 * 
 * Rest-state ritual ability where Kaelen cleans the soot from the Oathbringer blade, restoring steel polish and +0.10 Resolve.
 */
UCLASS()
class ASHENOATH_API UAshenBladeWipeCampfireGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenBladeWipeCampfireGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Soot")
	float RecoveredResolve = 0.10f;
};
