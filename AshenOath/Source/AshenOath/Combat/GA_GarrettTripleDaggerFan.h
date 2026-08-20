// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettTripleDaggerFan.generated.h"

/**
 * UGA_GarrettTripleDaggerFan
 *
 * Garrett's ranged dagger fan attack.
 * Fans 3 alchemically poisoned daggers dealing 90 Physical + 15 Poison damage/s for 4.0s in a 450u spread.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettTripleDaggerFan : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettTripleDaggerFan();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|DaggerFan")
	float BaseDamage = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|DaggerFan")
	float PoisonDamagePerSec = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|DaggerFan")
	float FanRadius = 450.0f;
};
