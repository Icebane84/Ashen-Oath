// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDynamicWeatherTypes.h"
#include "AshenGarrettAlchemicalInsulationGASAbility.generated.h"

/**
 * UAshenGarrettAlchemicalInsulationGASAbility
 * 
 * Garrett's field alchemy: Coats party gear with insulated tallow paste, mitigating environmental frostbite and acid rain degradation by 60%.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettAlchemicalInsulationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettAlchemicalInsulationGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Weather")
	float HazardMitigationRatio = 0.60f;
};
