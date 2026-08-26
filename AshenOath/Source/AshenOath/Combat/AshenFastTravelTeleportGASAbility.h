// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "World/AshenTacticalMapTypes.h"
#include "AshenFastTravelTeleportGASAbility.generated.h"

/**
 * UAshenFastTravelTeleportGASAbility
 * 
 * Channels 3.0s fast travel teleportation from an attuned sanctuary beacon to another discovered beacon.
 */
UCLASS()
class ASHENOATH_API UAshenFastTravelTeleportGASAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenFastTravelTeleportGASAbility();

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
	float ChannelDurationSeconds = 3.0f;
};
