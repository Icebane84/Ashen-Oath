// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenSomaticTremorGripGASAbility.generated.h"

/**
 * UAshenSomaticTremorGripGASAbility
 * 
 * Applies dynamic hand tremors and modulates parry timing windows during tachycardia episodes (Heart Rate > 140 BPM).
 */
UCLASS()
class ASHENOATH_API UAshenSomaticTremorGripGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSomaticTremorGripGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Somatics")
	float ParryWindowReductionFraction = 0.25f;
};
