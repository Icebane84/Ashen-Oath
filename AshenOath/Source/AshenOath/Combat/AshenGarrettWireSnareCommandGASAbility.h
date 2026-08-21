// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenGarrettWireSnareCommandGASAbility.generated.h"

/**
 * UAshenGarrettWireSnareCommandGASAbility
 * 
 * Orders Garrett to fire a high-tension wire snare to pin and immobilize the target.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettWireSnareCommandGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettWireSnareCommandGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Tactics")
	float SnareDurationSeconds = 3.5f;
};
