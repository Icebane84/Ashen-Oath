// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenSerafinaHolyDetonationBurstGASAbility.generated.h"

/**
 * UAshenSerafinaHolyDetonationBurstGASAbility
 * 
 * Step 3 of the Tripartite Combo: Serafina detonates a holy ward burst,
 * knocking the snared target down and priming the Harmonized Finisher.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaHolyDetonationBurstGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaHolyDetonationBurstGASAbility();

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
	float DetonationRadiusUU = 350.0f;
};
