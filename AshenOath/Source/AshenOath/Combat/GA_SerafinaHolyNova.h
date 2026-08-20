// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaHolyNova.generated.h"

/**
 * UGA_SerafinaHolyNova
 *
 * Serafina's Holy Nova — radiant burst ability dealing 195 Holy damage
 * to all enemies within a 600 unit sphere. Applies a 3-second
 * Radiant Weakness debuff reducing enemy damage output by 20%.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaHolyNova : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaHolyNova();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	/** Holy damage dealt to each enemy hit. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|HolyNova")
	float HolyDamage = 195.0f;

	/** Burst sphere radius. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|HolyNova")
	float NovaRadius = 600.0f;

	/** Radiant Weakness debuff duration in seconds. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|HolyNova")
	float WeaknessDebuffDuration = 3.0f;

	/** Damage reduction applied by Radiant Weakness (20%). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|HolyNova")
	float WeaknessDamageReduction = 0.20f;
};
