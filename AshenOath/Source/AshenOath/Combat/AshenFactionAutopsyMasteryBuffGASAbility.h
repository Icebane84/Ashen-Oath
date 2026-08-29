// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenFactionAutopsyMasteryBuffGASAbility.generated.h"

/**
 * UAshenFactionAutopsyMasteryBuffGASAbility
 * 
 * Anatomical Mastery: Passive bonus granting +25% critical damage and +40% poise damage against enemy genus whose autopsy case was solved in the Memory Palace.
 */
UCLASS()
class ASHENOATH_API UAshenFactionAutopsyMasteryBuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenFactionAutopsyMasteryBuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Forensic")
	float CritDamageMultiplierBonus = 0.25f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Forensic")
	float PoiseDamageMultiplierBonus = 0.40f;
};
