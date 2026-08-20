// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettTripwireDetonation.generated.h"

/**
 * UGA_GarrettTripwireDetonation
 *
 * Garrett's explosive trap detonation dealing 750 Fire damage and forcing enemy squad investigation.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettTripwireDetonation : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettTripwireDetonation();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|TripwireDetonation")
	float Damage = 750.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|TripwireDetonation")
	float Radius = 450.0f;
};
