// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenGarrettCartographerSurveyGASAbility.generated.h"

/**
 * UAshenGarrettCartographerSurveyGASAbility
 * 
 * Garrett uses his cartographer spyglass and compass to survey the region from high vantage points, clearing massive fog of war chunks.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettCartographerSurveyGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettCartographerSurveyGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Travel")
	float SurveyUnveilRadiusUU = 3500.0f;
};
