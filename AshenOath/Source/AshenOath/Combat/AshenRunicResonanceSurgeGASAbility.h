// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicResonanceSurgeGASAbility.generated.h"

/**
 * UAshenRunicResonanceSurgeGASAbility
 * 
 * Unleashes a radiant kinetic wave from socketed blade runes on heavy swings.
 */
UCLASS()
class ASHENOATH_API UAshenRunicResonanceSurgeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenRunicResonanceSurgeGASAbility();

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
	float SurgeRadiusUU = 800.0f;
};
