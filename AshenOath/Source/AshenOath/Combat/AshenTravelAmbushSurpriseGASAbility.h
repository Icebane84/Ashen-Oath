// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenTravelAmbushSurpriseGASAbility.generated.h"

/**
 * UAshenTravelAmbushSurpriseGASAbility
 * 
 * Roadside travel hazard ability: Triggers surprise skirmish encounter with -15% posture mitigation penalty.
 */
UCLASS()
class ASHENOATH_API UAshenTravelAmbushSurpriseGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTravelAmbushSurpriseGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Travel")
	float PosturePenaltyRatio = 0.15f;
};
