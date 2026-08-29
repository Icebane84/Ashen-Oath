// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenCavernRestorationBuffGASAbility.generated.h"

/**
 * UAshenCavernRestorationBuffGASAbility
 * 
 * Cavern Windbreak Buff: Applies 75% precipitation protection, halts blizzard freezing damage, and accelerates cooking speed by 2.0x.
 */
UCLASS()
class ASHENOATH_API UAshenCavernRestorationBuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCavernRestorationBuffGASAbility();

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
	float CookingRateBonusMultiplier = 2.00f;
};
