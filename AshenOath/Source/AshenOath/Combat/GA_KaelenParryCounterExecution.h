// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenParryCounterExecution.generated.h"

/**
 * UGA_KaelenParryCounterExecution
 *
 * Kaelen's frame-perfect parry counter dealing 1000 Physical damage + Instant posture break.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenParryCounterExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenParryCounterExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ParryCounterExecution")
	float Damage = 1000.0f;
};
