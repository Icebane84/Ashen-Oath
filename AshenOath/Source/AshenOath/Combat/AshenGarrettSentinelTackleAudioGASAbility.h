// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenGarrettSentinelTackleAudioGASAbility.generated.h"

/**
 * UAshenGarrettSentinelTackleAudioGASAbility
 * 
 * Garrett tackles Kaelen away from danger, ducking the entire soundtrack to -24dB for 1.2s to emphasize bone/mud impact.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettSentinelTackleAudioGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettSentinelTackleAudioGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Audio")
	float DuckingDurationSeconds = 1.2f;
};
