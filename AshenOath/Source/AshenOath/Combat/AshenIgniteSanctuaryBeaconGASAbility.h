// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenIgniteSanctuaryBeaconGASAbility.generated.h"

/**
 * UAshenIgniteSanctuaryBeaconGASAbility
 * 
 * Ignites an ancient stone beacon brazier using White Flame, clearing surrounding fog and establishing a permanent fast travel sanctuary.
 */
UCLASS()
class ASHENOATH_API UAshenIgniteSanctuaryBeaconGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenIgniteSanctuaryBeaconGASAbility();

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
	float FogUnveilBurstRadiusUU = 2500.0f;
};
