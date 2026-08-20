// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenRuthlessExecutionGASAbility.generated.h"

/**
 * UAshenRuthlessExecutionGASAbility
 * 
 * Lethal execution finisher on staggered enemies:
 * - Grants +Wrath to Kaelen's Soul State
 * - Evaluated pragmatically by Garrett, causes moral grief to Serafina
 */
UCLASS()
class ASHENOATH_API UAshenRuthlessExecutionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenRuthlessExecutionGASAbility();

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

	/** Executes lethal strike on staggered target */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Execution")
	bool ExecuteRuthlessStrike(AActor* StaggeredTargetActor);
};
