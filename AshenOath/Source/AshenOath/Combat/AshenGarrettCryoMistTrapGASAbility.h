// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario7Types.h"
#include "AshenGarrettCryoMistTrapGASAbility.generated.h"

/**
 * UAshenGarrettCryoMistTrapGASAbility
 * 
 * Garrett deploys an alchemical cryo-mist trap creating a 300uu localized cooling sanctuary.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettCryoMistTrapGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettCryoMistTrapGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Garrett")
	float MistCoolingRadiusUU = 300.0f;
};
