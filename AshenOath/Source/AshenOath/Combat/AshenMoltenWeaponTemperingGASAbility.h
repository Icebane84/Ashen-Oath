// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenMoltenWeaponTemperingGASAbility.generated.h"

/**
 * UAshenMoltenWeaponTemperingGASAbility
 * 
 * Kaelen tempers his blade in active volcanic magma, raising blade heat to 800°C for +40% fire damage.
 */
UCLASS()
class ASHENOATH_API UAshenMoltenWeaponTemperingGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMoltenWeaponTemperingGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Tempering")
	float MaxBladeHeatTempC = 800.0f;
};
