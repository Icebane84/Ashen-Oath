// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenTranscendentMemoryReintegrationGASAbility.generated.h"

/**
 * UAshenTranscendentMemoryReintegrationGASAbility
 * 
 * Unlocked via Transcended Consensus: Channels unified psychological memory synthesis, fully restoring party sanity (+50) and purging local memory battle anomalies.
 */
UCLASS()
class ASHENOATH_API UAshenTranscendentMemoryReintegrationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTranscendentMemoryReintegrationGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|CSE")
	float SanityPurgeAmount = 50.0f;
};
