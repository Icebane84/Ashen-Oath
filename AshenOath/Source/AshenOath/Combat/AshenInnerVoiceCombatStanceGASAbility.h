// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Soul/AshenInnerVoiceCompilerTypes.h"
#include "AshenInnerVoiceCombatStanceGASAbility.generated.h"

/**
 * UAshenInnerVoiceCombatStanceGASAbility
 * 
 * Gameplay Ability triggering inner voice reflections when morphing combat stances
 * during heightened internal friction or low stamina.
 */
UCLASS()
class ASHENOATH_API UAshenInnerVoiceCombatStanceGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenInnerVoiceCombatStanceGASAbility();

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

	/** Triggers voice compilation for stance morph */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Combat|Voice")
	bool TriggerStanceVoiceEcho(const FGameplayTag& NewStanceTag, float CurrentFriction);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Voice")
	float FrictionThresholdForVoice = 0.50f;
};
