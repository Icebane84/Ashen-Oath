// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenTemporalTacticalWheelGASAbility.generated.h"

/**
 * UAshenTemporalTacticalWheelGASAbility
 * 
 * Gameplay Ability toggling the squad command wheel and engaging slow-mo bullet time.
 */
UCLASS()
class ASHENOATH_API UAshenTemporalTacticalWheelGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTemporalTacticalWheelGASAbility();

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
	float MaxDilationDurationSeconds = 5.0f;
};
