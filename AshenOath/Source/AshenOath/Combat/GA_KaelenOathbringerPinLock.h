// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenOathbringerPinLock.generated.h"

/**
 * UGA_KaelenOathbringerPinLock
 *
 * Kaelen's heavy Oathbringer parry pin-lock ability.
 * Drives Oathbringer into the target (220 Physical damage), locking their movement coordinates
 * and opening a execution vulnerability window for Garrett.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenOathbringerPinLock : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenOathbringerPinLock();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PinLock")
	float Damage = 220.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PinLock")
	float PinRadius = 350.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PinLock")
	float PinDuration = 3.0f;
};
