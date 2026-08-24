// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenForensicMemoryEchoGASAbility.generated.h"

/**
 * UAshenForensicMemoryEchoGASAbility
 * 
 * Replays a 5-second phantom holographic echo of a recorded scenario choice.
 */
UCLASS()
class ASHENOATH_API UAshenForensicMemoryEchoGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenForensicMemoryEchoGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Echo")
	float MemoryEchoDurationSeconds = 5.0f;
};
