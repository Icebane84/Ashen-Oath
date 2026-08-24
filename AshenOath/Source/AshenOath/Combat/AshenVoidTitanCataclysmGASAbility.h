// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Scenarios/AshenScenario10Types.h"
#include "AshenVoidTitanCataclysmGASAbility.generated.h"

/**
 * UAshenVoidTitanCataclysmGASAbility
 * 
 * Final boss cataclysm ability raining void celestial meteors and collapsing island rings.
 */
UCLASS()
class ASHENOATH_API UAshenVoidTitanCataclysmGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenVoidTitanCataclysmGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Boss")
	float CataclysmDamagePerSecond = 200.0f;
};
