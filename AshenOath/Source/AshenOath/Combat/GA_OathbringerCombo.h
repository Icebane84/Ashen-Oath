// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_OathbringerCombo.generated.h"

/**
 * UGA_OathbringerCombo
 *
 * Gameplay Ability for Kaelen's primary Oathbringer greatsword combat combo.
 * Features a 3-hit combo sequence (Light 1 -> Light 2 -> Heavy Cleave)
 * with a hold-to-charge stance scaling damage, poise damage, and Oathbringer emissive glow.
 */
UCLASS()
class ASHENOATH_API UGA_OathbringerCombo : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_OathbringerCombo();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	int32 ComboStep = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float BaseDamage = 35.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float HeavyChargeMultiplier = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float StaminaCostLight = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float StaminaCostHeavy = 35.0f;
};
