// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenHearthstoneSanctuaryRegenGASAbility.generated.h"

/**
 * UAshenHearthstoneSanctuaryRegenGASAbility
 * 
 * Sanctuary Haven Aura: Restores +5.0 HP per second, normalizes body temperature to 37.0C, and completely halts sanity degradation.
 */
UCLASS()
class ASHENOATH_API UAshenHearthstoneSanctuaryRegenGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenHearthstoneSanctuaryRegenGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Survival")
	float HPRegenPerSecond = 5.0f;
};
