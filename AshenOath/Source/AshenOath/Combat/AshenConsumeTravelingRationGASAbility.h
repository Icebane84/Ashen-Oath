// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenSanctuarySurvivalTypes.h"
#include "AshenConsumeTravelingRationGASAbility.generated.h"

/**
 * UAshenConsumeTravelingRationGASAbility
 * 
 * Traveling Ration Ingestion: Prevents overland travel fatigue from clamping maximum stamina for 1800s.
 */
UCLASS()
class ASHENOATH_API UAshenConsumeTravelingRationGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenConsumeTravelingRationGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Survival")
	float DurationSeconds = 1800.0f;
};
