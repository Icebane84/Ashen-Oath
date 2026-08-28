// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenSymbioticFlowCatharsisGASAbility.generated.h"

/**
 * UAshenSymbioticFlowCatharsisGASAbility
 * 
 * Channels 8.0-second Symbiotic Flow State, instantly silencing Stem 02 whispers and restoring +40 sanity.
 */
UCLASS()
class ASHENOATH_API UAshenSymbioticFlowCatharsisGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSymbioticFlowCatharsisGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Convergence")
	float SanityRestored = 40.0f;
};
