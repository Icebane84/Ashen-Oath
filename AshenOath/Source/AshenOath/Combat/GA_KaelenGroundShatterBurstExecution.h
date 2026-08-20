// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenGroundShatterBurstExecution.generated.h"

/**
 * UGA_KaelenGroundShatterBurstExecution
 *
 * Kaelen's heavy ground slam dealing 800 Physical damage, fracturing floor decals, and staggering enemies in a 500u radius.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenGroundShatterBurstExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenGroundShatterBurstExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|GroundShatterBurst")
	float Damage = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|GroundShatterBurst")
	float Radius = 500.0f;
};
