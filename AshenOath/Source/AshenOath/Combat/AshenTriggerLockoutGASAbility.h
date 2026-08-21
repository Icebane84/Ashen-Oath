// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenTriggerLockoutGASAbility.generated.h"

/**
 * UAshenTriggerLockoutGASAbility
 * 
 * Gameplay Ability actuating 100% mechanical trigger hard-stop lockout (Priority 1).
 */
UCLASS()
class ASHENOATH_API UAshenTriggerLockoutGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTriggerLockoutGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Haptics")
	float LockoutDurationSeconds = 1.5f;
};
