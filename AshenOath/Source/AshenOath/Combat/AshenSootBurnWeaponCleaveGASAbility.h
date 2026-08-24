// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenSootBurnWeaponCleaveGASAbility.generated.h"

/**
 * UAshenSootBurnWeaponCleaveGASAbility
 * 
 * Converts accumulated weapon soot and slag into superheated thermal burst damage on contact (+40 Heat Damage).
 */
UCLASS()
class ASHENOATH_API UAshenSootBurnWeaponCleaveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSootBurnWeaponCleaveGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Soot")
	float BaseHeatDamage = 40.0f;
};
