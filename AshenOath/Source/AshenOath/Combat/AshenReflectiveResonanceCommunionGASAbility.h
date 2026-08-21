// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenReflectiveResonanceCommunionGASAbility.generated.h"

/**
 * UAshenReflectiveResonanceCommunionGASAbility
 * 
 * Group rest communion granting +15% Holy Resistance and +10% Poise.
 */
UCLASS()
class ASHENOATH_API UAshenReflectiveResonanceCommunionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenReflectiveResonanceCommunionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Hearth")
	float HolyResistanceBonusPercent = 15.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Hearth")
	float PoiseBonusPercent = 10.0f;
};
