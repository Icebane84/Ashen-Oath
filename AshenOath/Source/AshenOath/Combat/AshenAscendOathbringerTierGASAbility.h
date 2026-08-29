// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenAscendOathbringerTierGASAbility.generated.h"

/**
 * UAshenAscendOathbringerTierGASAbility
 * 
 * Blade Ascension: Channels ancient crucible energies at a Sanctuary Hearth to ascend Oathbringer to its next metallurgical tier.
 */
UCLASS()
class ASHENOATH_API UAshenAscendOathbringerTierGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenAscendOathbringerTierGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|RunicForge")
	EOathbringerAscensionTier TargetAscensionTier = EOathbringerAscensionTier::Tier3_SunderedSovereign;
};
