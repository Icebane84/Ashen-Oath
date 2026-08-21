// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenGarrettWireTensionHapticGASAbility.generated.h"

/**
 * UAshenGarrettWireTensionHapticGASAbility
 * 
 * Gameplay Ability applying stepped spring resistance on L2 during wire snare pulls.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettWireTensionHapticGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettWireTensionHapticGASAbility();

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
	float MaxWireTension = 0.85f;
};
