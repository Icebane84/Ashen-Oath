// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenSerafinaSacredAuraHapticGASAbility.generated.h"

/**
 * UAshenSerafinaSacredAuraHapticGASAbility
 * 
 * Gameplay Ability pulsing smooth harmonic rumble and soft trigger feedback during bulwark shields.
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaSacredAuraHapticGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSerafinaSacredAuraHapticGASAbility();

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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen|Haptics")
	float AuraDurationSeconds = 4.0f;
};
