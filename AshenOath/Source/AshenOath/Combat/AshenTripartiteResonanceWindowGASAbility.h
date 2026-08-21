// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenTripartiteResonanceTypes.h"
#include "AshenTripartiteResonanceWindowGASAbility.generated.h"

/**
 * UAshenTripartiteResonanceWindowGASAbility
 * 
 * Initiator ability opening the 2.5s Tripartite Resonance Window upon landing
 * a heavy stagger or cleave.
 */
UCLASS()
class ASHENOATH_API UAshenTripartiteResonanceWindowGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTripartiteResonanceWindowGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Trio")
	float WindowDurationSeconds = 2.5f;
};
