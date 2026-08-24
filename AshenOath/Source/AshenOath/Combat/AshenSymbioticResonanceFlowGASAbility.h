// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenSymbioticResonanceFlowGASAbility.generated.h"

/**
 * UAshenSymbioticResonanceFlowGASAbility
 * 
 * Triggers the 8-second Symbiotic Flow State, silencing Oathbringer's parasitic hum and doubling party stamina recovery.
 */
UCLASS()
class ASHENOATH_API UAshenSymbioticResonanceFlowGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSymbioticResonanceFlowGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Audio|Flow")
	float FlowDurationSeconds = 8.0f;
};
