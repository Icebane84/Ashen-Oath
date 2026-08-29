// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenExposeCompanionContradictionGASAbility.generated.h"

/**
 * UAshenExposeCompanionContradictionGASAbility
 * 
 * Contradiction Breakthrough: Confronts companion testimony with forensic proof, reducing cognitive dissonance (D < 0.20) and unlocking harmony synergy.
 */
UCLASS()
class ASHENOATH_API UAshenExposeCompanionContradictionGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenExposeCompanionContradictionGASAbility();

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
	float DissonanceReduction = 0.40f;
};
