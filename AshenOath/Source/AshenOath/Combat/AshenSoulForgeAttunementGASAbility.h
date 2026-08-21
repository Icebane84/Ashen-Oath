// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenSoulForgeAttunementGASAbility.generated.h"

/**
 * UAshenSoulForgeAttunementGASAbility
 * 
 * Gameplay Ability executing the soul-forge transmutation ritual at a campfire hearth.
 */
UCLASS()
class ASHENOATH_API UAshenSoulForgeAttunementGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSoulForgeAttunementGASAbility();

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
	float ForgeRitualDurationSeconds = 2.0f;
};
