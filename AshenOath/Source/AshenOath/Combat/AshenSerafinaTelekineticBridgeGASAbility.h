// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario9Types.h"
#include "AshenSerafinaTelekineticBridgeGASAbility.generated.h"

/**
 * UAshenSerafinaTelekineticBridgeGASAbility
 * 
 * Serafina channels telekinetic light to materialize a resonant bridge spanning a 1500uu chasm for 10 seconds.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaTelekineticBridgeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaTelekineticBridgeGASAbility();

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
	float BridgeLifespanSeconds = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Serafina")
	float BridgeSpanUU = 1500.0f;
};
