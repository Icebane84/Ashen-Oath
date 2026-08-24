// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Companions/AshenTripartiteCognitiveLoopTypes.h"
#include "AshenGarrettFlankInterlockGASAbility.generated.h"

/**
 * UAshenGarrettFlankInterlockGASAbility
 * 
 * Garrett maneuvers to the enemy's rear flank, executing an off-hand blade lock that pins enemy turn rate.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettFlankInterlockGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettFlankInterlockGASAbility();

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
	float FlankLockDurationSeconds = 2.5f;
};
