// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenWhiteFlameHearthIgnitionGASAbility.generated.h"

/**
 * UAshenWhiteFlameHearthIgnitionGASAbility
 * 
 * Channels Kaelen's White Flame into the ancient Hearth Brazier, advancing ignition while burning off Integration Debt.
 */
UCLASS()
class ASHENOATH_API UAshenWhiteFlameHearthIgnitionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenWhiteFlameHearthIgnitionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Scenario6|Hearth")
	float ChannelRatePerSecond = 0.20f;
};
