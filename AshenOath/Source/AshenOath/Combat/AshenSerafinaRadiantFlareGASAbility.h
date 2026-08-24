// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenSerafinaRadiantFlareGASAbility.generated.h"

/**
 * UAshenSerafinaRadiantFlareGASAbility
 * 
 * Serafina releases a radiant White Flame flare illuminating a 1200uu radius for 6 seconds and blinding shadow beasts.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaRadiantFlareGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaRadiantFlareGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Serafina")
	float FlareDurationSeconds = 6.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Serafina")
	float FlareRadiusUU = 1200.0f;
};
