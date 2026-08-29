// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenHeavyArmorPoiseHyperarmorGASAbility.generated.h"

/**
 * UAshenHeavyArmorPoiseHyperarmorGASAbility
 * 
 * Hyper-armor posture state granted to HeavyLoad wielder during active weapon swing release frames, preventing stagger from attacks under 60 poise damage.
 */
UCLASS()
class ASHENOATH_API UAshenHeavyArmorPoiseHyperarmorGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenHeavyArmorPoiseHyperarmorGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Kinematics")
	float HyperArmorPoiseThreshold = 60.0f;
};
