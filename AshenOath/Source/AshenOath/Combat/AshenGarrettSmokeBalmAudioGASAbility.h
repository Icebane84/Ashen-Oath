// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenGarrettSmokeBalmAudioGASAbility.generated.h"

/**
 * UAshenGarrettSmokeBalmAudioGASAbility
 * 
 * Garrett throws a Sulfurous Smoke Balm, dropping the audio cutoff to 450Hz (dense fog sensory deprivation).
 */
UCLASS()
class ASHENOATH_API UAshenGarrettSmokeBalmAudioGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettSmokeBalmAudioGASAbility();

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
	float SmokeDurationSeconds = 5.0f;
};
