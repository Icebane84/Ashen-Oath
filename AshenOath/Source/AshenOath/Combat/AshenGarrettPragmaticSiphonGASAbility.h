// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenGarrettPragmaticSiphonGASAbility.generated.h"

/**
 * UAshenGarrettPragmaticSiphonGASAbility
 * 
 * Unlocked via Pragmatic Quest Resolution: Garrett siphons vital fluids on poise breaks, restoring 15% Max Health to the party.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettPragmaticSiphonGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenGarrettPragmaticSiphonGASAbility();

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
	float PartyHealPercent = 0.15f;
};
