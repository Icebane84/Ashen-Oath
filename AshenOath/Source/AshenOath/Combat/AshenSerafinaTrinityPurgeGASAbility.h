// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenSerafinaTrinityPurgeGASAbility.generated.h"

/**
 * UAshenSerafinaTrinityPurgeGASAbility
 * 
 * Step 3 of Trinity Strike: Serafina channels a concentrated White Flame beam, executing the 3.5x burst finisher and cleansing paranoia.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaTrinityPurgeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaTrinityPurgeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Trinity")
	float FinisherDamageMultiplier = 3.50f;
};
