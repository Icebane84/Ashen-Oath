// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenInspectRelicGASAbility.generated.h"

/**
 * UAshenInspectRelicGASAbility
 * 
 * Gameplay Ability activating the 3D relic inspection mode and audio hum.
 */
UCLASS()
class ASHENOATH_API UAshenInspectRelicGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenInspectRelicGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Archive")
	float MaxInspectDurationSeconds = 60.0f;
};
