// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario1CauterizedHeartTypes.h"
#include "AshenNullZoneCascadeGASAbility.generated.h"

/**
 * UAshenNullZoneCascadeGASAbility
 * 
 * Gameplay Ability initiating the Null Zone cascade in Oakhaven Chapel, stripping passive buffs.
 */
UCLASS()
class ASHENOATH_API UAshenNullZoneCascadeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenNullZoneCascadeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario1|GAS")
	float NullZoneRadiusCentimeters = 1500.0f;
};
