// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenPsychologicalFractureDebuffGASAbility.generated.h"

/**
 * UAshenPsychologicalFractureDebuffGASAbility
 * 
 * Debuff state triggered during Psychological Fracture (D > 0.75): increases tandem stamina costs by +20% and introduces a 0.60s companion assist hesitation delay.
 */
UCLASS()
class ASHENOATH_API UAshenPsychologicalFractureDebuffGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenPsychologicalFractureDebuffGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|CSE")
	float TandemStaminaPenalty = 0.20f;
};
