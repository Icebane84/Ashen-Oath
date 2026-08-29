// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenCombatKinematicsTypes.h"
#include "AshenGlancingDeflectionRiposteGASAbility.generated.h"

/**
 * UAshenGlancingDeflectionRiposteGASAbility
 * 
 * Perfect deflection ability triggering on frame-perfect parries: restores +50 stamina, builds +35 White Flame, and grants +25% attack power on the next riposte.
 */
UCLASS()
class ASHENOATH_API UAshenGlancingDeflectionRiposteGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGlancingDeflectionRiposteGASAbility();

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
	float StaminaRestored = 50.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Kinematics")
	float WhiteFlameGained = 35.0f;
};
