// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenRelicResonancePurgeGASAbility.generated.h"

/**
 * UAshenRelicResonancePurgeGASAbility
 * 
 * Gameplay Ability purging blight corruption from discovered relics to yield soul embers.
 */
UCLASS()
class ASHENOATH_API UAshenRelicResonancePurgeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenRelicResonancePurgeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Archive")
	float PurgedSoulEmbersYield = 50.0f;
};
