// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenNightsteelResonancePulseGASAbility.generated.h"

/**
 * UAshenNightsteelResonancePulseGASAbility
 * 
 * Discharges accumulated nightsteel kinetic resonance in a 360-degree radial blast (600uu).
 */
UCLASS()
class ASHENOATH_API UAshenNightsteelResonancePulseGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenNightsteelResonancePulseGASAbility();

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
	float BlastRadiusUU = 600.0f;
};
