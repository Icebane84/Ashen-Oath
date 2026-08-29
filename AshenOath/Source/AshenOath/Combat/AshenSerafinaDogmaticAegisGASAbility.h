// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Narrative/AshenCSEQuestBoardTypes.h"
#include "AshenSerafinaDogmaticAegisGASAbility.generated.h"

/**
 * UAshenSerafinaDogmaticAegisGASAbility
 * 
 * Unlocked via Dogmatic Quest Resolution: Serafina erects a holy aegis granting 100% immunity to elemental and status debuffs for 8.0s.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaDogmaticAegisGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaDogmaticAegisGASAbility();

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
	float AegisDurationSeconds = 8.0f;
};
