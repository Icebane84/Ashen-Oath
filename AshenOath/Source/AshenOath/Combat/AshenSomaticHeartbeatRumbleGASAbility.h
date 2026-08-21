// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenSomaticHeartbeatRumbleGASAbility.generated.h"

/**
 * UAshenSomaticHeartbeatRumbleGASAbility
 * 
 * Modulates grip vibration pulse rates matching Kaelen's physiological heart rate (60 - 140 BPM).
 */
UCLASS()
class ASHENOATH_API UAshenSomaticHeartbeatRumbleGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSomaticHeartbeatRumbleGASAbility();

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
	float HeartRateBPM = 60.0f;
};
