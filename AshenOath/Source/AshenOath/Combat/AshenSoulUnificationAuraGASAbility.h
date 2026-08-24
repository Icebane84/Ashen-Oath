// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenSoulUnificationAuraGASAbility.generated.h"

/**
 * UAshenSoulUnificationAuraGASAbility
 * 
 * Radiant aura emanating from the unified tri-soul entity, granting stagger immunity and emitting Solfeggio triad harmonics (800uu radius).
 */
UCLASS()
class ASHENOATH_API UAshenSoulUnificationAuraGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSoulUnificationAuraGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Aura")
	float AuraRadiusUU = 800.0f;
};
