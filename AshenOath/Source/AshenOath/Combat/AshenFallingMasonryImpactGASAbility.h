// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenFallingMasonryImpactGASAbility.generated.h"

/**
 * UAshenFallingMasonryImpactGASAbility
 * 
 * Environmental hazard execution ability delivering crushing damage and knockdown physics to actors caught inside the impact zone.
 */
UCLASS()
class ASHENOATH_API UAshenFallingMasonryImpactGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenFallingMasonryImpactGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Hazard")
	float BaseCrushingDamage = 600.0f;
};
