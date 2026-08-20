// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenGroundShatterStrike.generated.h"

/**
 * UGA_KaelenGroundShatterStrike
 *
 * Kaelen's heavy downward slam fracturing terrain in a 400u cone.
 * Deals 310 Physical damage and causes a 1.5s knockdown.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenGroundShatterStrike : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenGroundShatterStrike();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|GroundShatter")
	float Damage = 310.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|GroundShatter")
	float ConeRadius = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|GroundShatter")
	float KnockdownDuration = 1.5f;
};
