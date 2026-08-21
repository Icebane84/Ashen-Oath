// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "AshenDecodeRunicInscriptionGASAbility.generated.h"

/**
 * UAshenDecodeRunicInscriptionGASAbility
 * 
 * Gameplay Ability deciphering an inscription to unlock permanent lore and crafting blueprints.
 */
UCLASS()
class ASHENOATH_API UAshenDecodeRunicInscriptionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenDecodeRunicInscriptionGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Archive")
	float DecodeTimeRequiredSeconds = 3.0f;
};
