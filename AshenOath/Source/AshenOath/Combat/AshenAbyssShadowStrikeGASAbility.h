// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario8Types.h"
#include "AshenAbyssShadowStrikeGASAbility.generated.h"

/**
 * UAshenAbyssShadowStrikeGASAbility
 * 
 * Precision strike executing an ambush attack against sonar-tagged enemies in darkness (+75% Critical Damage).
 */
UCLASS()
class ASHENOATH_API UAshenAbyssShadowStrikeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenAbyssShadowStrikeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Abyss")
	float SonarAmbushCriticalMultiplier = 1.75f;
};
