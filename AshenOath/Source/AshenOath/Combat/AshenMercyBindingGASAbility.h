// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenMercyBindingGASAbility.generated.h"

/**
 * UAshenMercyBindingGASAbility
 * 
 * Non-lethal combat ability binding a staggered foe with consecration wards:
 * - Grants +Grace to Kaelen's Soul State
 * - Earns Serafina's profound moral gratitude
 */
UCLASS()
class ASHENOATH_API UAshenMercyBindingGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMercyBindingGASAbility();

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

	/** Executes mercy binding on staggered target */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Mercy")
	bool ExecuteMercyBinding(AActor* StaggeredTargetActor);
};
