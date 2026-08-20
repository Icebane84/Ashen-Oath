// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettPoisonBladeExecution.generated.h"

/**
 * UGA_GarrettPoisonBladeExecution
 *
 * Garrett's stealth execution GAS ability dealing 550 Physical + 150 Poison damage over 4.0s from stealth.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettPoisonBladeExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettPoisonBladeExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PoisonBladeExecution")
	float Damage = 550.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PoisonBladeExecution")
	float Radius = 300.0f;
};
