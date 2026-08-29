// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenInspectForensicClueGASAbility.generated.h"

/**
 * UAshenInspectForensicClueGASAbility
 * 
 * Forensic Investigation: Channels White Flame through Kaelen's lens to examine a corpse, altar, or stela, discovering clues.
 */
UCLASS()
class ASHENOATH_API UAshenInspectForensicClueGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenInspectForensicClueGASAbility();

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
	float ScanDurationSeconds = 1.50f;
};
