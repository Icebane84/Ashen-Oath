// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenParasiticBloodDrainDebuffGASAbility.generated.h"

/**
 * UAshenParasiticBloodDrainDebuffGASAbility
 * 
 * Imposes health drain when corruption exceeds 70% without Gloomwood chemical stabilization.
 */
UCLASS()
class ASHENOATH_API UAshenParasiticBloodDrainDebuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenParasiticBloodDrainDebuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Blade")
	float BloodDrainDamagePerSecond = 15.0f;
};
