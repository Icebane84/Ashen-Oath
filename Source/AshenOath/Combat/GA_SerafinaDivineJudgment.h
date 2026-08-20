// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaDivineJudgment.generated.h"

/**
 * UGA_SerafinaDivineJudgment
 *
 * Serafina's high-impact holy AoE combo finisher GAS ability.
 * Uses SphereOverlapActors within 600uu radius to deal 300 Holy Damage to enemies,
 * triggering pooled holy explosion VFX.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaDivineJudgment : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaDivineJudgment();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float DivineDamage = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float BlastRadius = 600.0f;
};
