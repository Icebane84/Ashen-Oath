// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenGarrettWireTrapSnareGASAbility.generated.h"

/**
 * UAshenGarrettWireTrapSnareGASAbility
 * 
 * Step 2 of the Tripartite Combo: Garrett fires a nightsteel wire snare,
 * immobilizing the target and exposing posture.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettWireTrapSnareGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettWireTrapSnareGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Garrett")
	float SnareDurationSeconds = 2.0f;
};
