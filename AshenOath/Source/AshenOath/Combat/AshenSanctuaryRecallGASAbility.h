// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenSanctuaryRecallGASAbility.generated.h"

/**
 * UAshenSanctuaryRecallGASAbility
 * 
 * Emergency warp ability channeling a retreat back to the last attuned campfire sanctuary hearth.
 */
UCLASS()
class ASHENOATH_API UAshenSanctuaryRecallGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSanctuaryRecallGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Travel")
	float RecallChannelDurationSeconds = 5.0f;
};
