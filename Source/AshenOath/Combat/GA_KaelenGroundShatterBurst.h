// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenGroundShatterBurst.generated.h"

/**
 * UGA_KaelenGroundShatterBurst
 *
 * Kaelen's ultimate seismic ground shatter burst.
 * Deals 480 Physical damage in a 550u 360° circle, fracturing terrain and causing 2.0s knockdowns.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenGroundShatterBurst : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenGroundShatterBurst();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ShatterBurst")
	float Damage = 480.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ShatterBurst")
	float Radius = 550.0f;
};
