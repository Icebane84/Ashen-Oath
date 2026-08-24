// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenGloomwoodNeedleStabilizationGASAbility.generated.h"

/**
 * UAshenGloomwoodNeedleStabilizationGASAbility
 * 
 * Garrett fires a Gloomwood Sap Needle into Kaelen's forearm, chemically freezing corruption for 8 seconds.
 */
UCLASS()
class ASHENOATH_API UAshenGloomwoodNeedleStabilizationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGloomwoodNeedleStabilizationGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Gloomwood")
	float FreezeDurationSeconds = 8.0f;
};
