// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenChaosNavmeshTypes.h"
#include "AshenSerafinaDebrisDisintegrationGASAbility.generated.h"

/**
 * UAshenSerafinaDebrisDisintegrationGASAbility
 * 
 * Serafina channels a concentrated White Flame beam that dissolves stone blockades into ash.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaDebrisDisintegrationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaDebrisDisintegrationGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Serafina")
	float DisintegrationRangeUU = 600.0f;
};
