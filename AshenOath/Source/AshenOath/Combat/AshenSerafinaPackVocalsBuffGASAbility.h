// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenSerafinaPackVocalsBuffGASAbility.generated.h"

/**
 * UAshenSerafinaPackVocalsBuffGASAbility
 * 
 * Serafina delivers the vocal anchor ('I am holding the center'), granting the party +20% poise recovery and crowd control immunity.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaPackVocalsBuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaPackVocalsBuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Vocals")
	float PoiseRecoveryBonusPercent = 0.20f;
};
