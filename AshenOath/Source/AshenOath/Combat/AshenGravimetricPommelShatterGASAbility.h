// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenRunicForgeTypes.h"
#include "AshenGravimetricPommelShatterGASAbility.generated.h"

/**
 * UAshenGravimetricPommelShatterGASAbility
 * 
 * Mordhau Sigil Inscription: Half-sword inverted pommel strike shattering 100% of plate armor and emitting a localized gravimetric collapse shockwave.
 */
UCLASS()
class ASHENOATH_API UAshenGravimetricPommelShatterGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGravimetricPommelShatterGASAbility();

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
	float ArmorPenetrationScale = 1.00f; // 100% Armor Penetration
};
