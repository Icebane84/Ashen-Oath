// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenTraumaVeinSurgeGASAbility.generated.h"

/**
 * UAshenTraumaVeinSurgeGASAbility
 * 
 * Channels dark subcutaneous vein corruption into an explosive kinetic dash and strike (+50% lunge velocity).
 */
UCLASS()
class ASHENOATH_API UAshenTraumaVeinSurgeGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenTraumaVeinSurgeGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Combat|Somatics")
	float LungeVelocityBoost = 1.50f;
};
