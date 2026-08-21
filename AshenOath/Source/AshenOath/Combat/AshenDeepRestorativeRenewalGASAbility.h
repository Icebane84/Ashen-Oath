// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenDeepRestorativeRenewalGASAbility.generated.h"

/**
 * UAshenDeepRestorativeRenewalGASAbility
 * 
 * Full recovery ability restoring 100% Resolve and clearing all temporary debuffs.
 */
UCLASS()
class ASHENOATH_API UAshenDeepRestorativeRenewalGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenDeepRestorativeRenewalGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Hearth")
	float ResolveRestorationPercent = 1.0f; // 100%
};
