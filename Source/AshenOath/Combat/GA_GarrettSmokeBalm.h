// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettSmokeBalm.generated.h"

/**
 * UGA_GarrettSmokeBalm
 *
 * Gameplay Ability wrapping Garrett's Sulfurous Smoke Balm throw.
 * Creates a 400uu blind zone by triggering ThrowSulfurousSmokeBalm()
 * on UAshenOath_AlchemicalComponent, disrupting enemy vision and creating
 * tactical withdrawal corridors.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettSmokeBalm : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettSmokeBalm();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;
};
