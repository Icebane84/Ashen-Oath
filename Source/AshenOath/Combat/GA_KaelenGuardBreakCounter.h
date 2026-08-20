// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenGuardBreakCounter.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGuardBreakCounterExecutedSignature, AActor*, Target, float, DamageDealt);

/**
 * UGA_KaelenGuardBreakCounter
 *
 * Kaelen's heavy retaliatory counter-attack ability triggered following a successful parry or block.
 * Deals 180 Physical Damage and 85 Poise Damage to target within 300uu.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenGuardBreakCounter : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenGuardBreakCounter();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float CounterDamage = 180.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float PoiseDamage = 85.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float CounterRadius = 300.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Ability|Events")
	FOnGuardBreakCounterExecutedSignature OnCounterExecuted;
};
