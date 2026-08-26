// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenRubbleScrambleTraversalGASAbility.generated.h"

/**
 * UAshenRubbleScrambleTraversalGASAbility
 * 
 * Agile traversal ability enabling characters to swiftly scramble and mantle across uneven physical rubble clusters.
 */
UCLASS()
class ASHENOATH_API UAshenRubbleScrambleTraversalGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenRubbleScrambleTraversalGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Traversal")
	float ScrambleSpeedMultiplier = 1.35f;
};
