// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettGrapplingHook.generated.h"

/**
 * UGA_GarrettGrapplingHook
 *
 * Garrett's tactical mobility grapple hook ability.
 * Launches a cable up to 700u pulling Garrett to ledge geometry or pulling targets towards him.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettGrapplingHook : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettGrapplingHook();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Grapple")
	float MaxGrappleRange = 700.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Grapple")
	float PullForce = 1400.0f;
};
