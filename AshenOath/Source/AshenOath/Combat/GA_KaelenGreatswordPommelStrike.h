// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenGreatswordPommelStrike.generated.h"

/**
 * UGA_KaelenGreatswordPommelStrike
 *
 * Kaelen's heavy Oathbringer greatsword pommel strike ability.
 * Drives the heavy pommel forward to shatter enemy posture (180 Physical + 90 Poise damage)
 * in a 300u cone, causing guard break and a 2.0s knockdown.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenGreatswordPommelStrike : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenGreatswordPommelStrike();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PommelStrike")
	float Damage = 180.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PommelStrike")
	float PoiseDamage = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PommelStrike")
	float StrikeRadius = 300.0f;
};
