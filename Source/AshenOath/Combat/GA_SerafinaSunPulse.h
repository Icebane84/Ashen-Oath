// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaSunPulse.generated.h"

/**
 * UGA_SerafinaSunPulse
 *
 * Serafina's radiant sun pulse ability.
 * Deals 280 Holy damage in a 500u radius, dispels spectral illusions,
 * and forces phase-shifting bosses into physical state via Consecrated Ground anchoring.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaSunPulse : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaSunPulse();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SunPulse")
	float Damage = 280.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SunPulse")
	float PulseRadius = 500.0f;
};
