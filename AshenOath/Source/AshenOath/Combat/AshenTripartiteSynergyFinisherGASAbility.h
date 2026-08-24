// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenTripartiteSynergyFinisherGASAbility.generated.h"

/**
 * UAshenTripartiteSynergyFinisherGASAbility
 * 
 * Synchronized 3-person finisher burst (Kaelen Cleave + Garrett X-Flank + Serafina Light Burst) scaling up to 3.0x damage.
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteSynergyFinisherGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTripartiteSynergyFinisherGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Tripartite")
	float MaxDamageMultiplier = 3.0f;
};
