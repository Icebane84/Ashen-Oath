// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenResonanceShiftAttack.generated.h"

/**
 * UGA_KaelenResonanceShiftAttack
 *
 * High-cost GAS attack shifting Resonance meter by 35 points in a single 480 damage burst.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenResonanceShiftAttack : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenResonanceShiftAttack();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ResonanceShift")
	float Damage = 480.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ResonanceShift")
	float ResonanceShiftDelta = 35.0f;
};
