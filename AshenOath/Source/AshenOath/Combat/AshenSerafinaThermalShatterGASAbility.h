// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenSerafinaThermalShatterGASAbility.generated.h"

/**
 * UAshenSerafinaThermalShatterGASAbility
 * 
 * Serafina channels intense White Flame heat into cold stone masonry, applying thermal shock that weakens durability by 60%.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaThermalShatterGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaThermalShatterGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Demolition")
	float ThermalDurabilityReductionPercent = 0.60f;
};
