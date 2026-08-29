// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenSynthesizeMemoryShardGASAbility.generated.h"

/**
 * UAshenSynthesizeMemoryShardGASAbility
 * 
 * Mindscape Synthesis: Connects the final evidence thread in the Memory Palace, triggering spectral reenactment and granting psychic catharsis.
 */
UCLASS()
class ASHENOATH_API UAshenSynthesizeMemoryShardGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSynthesizeMemoryShardGASAbility();

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
	float CatharsisSanityGain = 50.0f;
};
