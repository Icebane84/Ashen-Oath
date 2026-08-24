// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario6Types.h"
#include "AshenHearthDefenseShockwaveGASAbility.generated.h"

/**
 * UAshenHearthDefenseShockwaveGASAbility
 * 
 * Unleashed upon completing the Hearth ignition, releasing a massive radial thermal wave that repels frost enemies.
 */
UCLASS()
class ASHENOATH_API UAshenHearthDefenseShockwaveGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenHearthDefenseShockwaveGASAbility();

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
	float ShockwaveRadiusUU = 2000.0f;
};
