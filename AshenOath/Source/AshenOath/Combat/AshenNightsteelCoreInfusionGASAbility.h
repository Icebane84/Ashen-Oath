// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenNightsteelCoreInfusionGASAbility.generated.h"

/**
 * UAshenNightsteelCoreInfusionGASAbility
 * 
 * Gameplay Ability infusing a boss Nightsteel core into the primary blade socket.
 */
UCLASS()
class ASHENOATH_API UAshenNightsteelCoreInfusionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenNightsteelCoreInfusionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Reliquary")
	float AddedMassKg = 35.0f;
};
