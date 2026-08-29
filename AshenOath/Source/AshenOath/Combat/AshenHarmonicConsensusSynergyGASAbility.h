// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenHarmonicConsensusSynergyGASAbility.generated.h"

/**
 * UAshenHarmonicConsensusSynergyGASAbility
 * 
 * Channels +30% tandem synergy damage and grants instant companion assist cooldown resets during Harmonic Consensus (D < 0.25).
 */
UCLASS()
class ASHENOATH_API UAshenHarmonicConsensusSynergyGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenHarmonicConsensusSynergyGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|CSE")
	float SynergyDamageBonus = 0.30f;
};
