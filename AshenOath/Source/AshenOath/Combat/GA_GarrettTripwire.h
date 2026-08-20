// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettTripwire.generated.h"

/**
 * UGA_GarrettTripwire
 *
 * Gameplay Ability wrapping Garrett's Ghostbloom Tripwire deployment.
 * Deploys a spring-loaded clockwork Ghostbloom Tripwire at the target location
 * via DeployGhostbloomTripwire() on UAshenOath_AlchemicalComponent.
 * Enemies crossing the wire trigger a 600uu stun burst.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettTripwire : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettTripwire();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;
};
