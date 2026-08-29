// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenPsychicCatharsisSanityPurgeGASAbility.generated.h"

/**
 * UAshenPsychicCatharsisSanityPurgeGASAbility
 * 
 * Psychic Catharsis: Cleanses Eldrin whisper delirium and permanently restores +50.0 Sanity upon solving a forensic memory.
 */
UCLASS()
class ASHENOATH_API UAshenPsychicCatharsisSanityPurgeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPsychicCatharsisSanityPurgeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Forensic")
	float SanityPurgeAmount = 50.0f;
};
