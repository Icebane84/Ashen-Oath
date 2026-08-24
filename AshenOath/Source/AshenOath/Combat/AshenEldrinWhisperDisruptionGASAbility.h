// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenEldrinWhisperDisruptionGASAbility.generated.h"

/**
 * UAshenEldrinWhisperDisruptionGASAbility
 * 
 * Eldrin's trapped spirit screams through the nightsteel hilt, staggering all enemies in an 800uu radius.
 */
UCLASS()
class ASHENOATH_API UAshenEldrinWhisperDisruptionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenEldrinWhisperDisruptionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Whisper")
	float DisruptionRadiusUU = 800.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Whisper")
	float StunDurationSeconds = 2.5f;
};
