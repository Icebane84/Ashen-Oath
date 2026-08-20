// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_AshbringerChargedSlam.generated.h"

/**
 * UGA_AshbringerChargedSlam
 *
 * Oathbringer charged ground slam — a 2-second wind-up delivers 340 Physical damage
 * in a 500-unit radius and applies a 2-second Stagger to all targets hit.
 * Costs 40 Stamina. Cannot activate while exhausted.
 */
UCLASS()
class ASHENOATH_API UGA_AshbringerChargedSlam : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_AshbringerChargedSlam();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	/** Physical damage at slam impact. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ChargedSlam")
	float SlamDamage = 340.0f;

	/** Ground slam AoE radius. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ChargedSlam")
	float SlamRadius = 500.0f;

	/** Stagger debuff duration in seconds. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ChargedSlam")
	float StaggerDuration = 2.0f;

	/** Stamina cost of the charged slam. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ChargedSlam")
	float StaminaCost = 40.0f;
};
