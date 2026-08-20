// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenLethalSilentDualExecution.generated.h"

/**
 * UGA_KaelenLethalSilentDualExecution
 *
 * Kaelen's silent peak-resonance dual execution dealing 1500 damage in pure lethal silence.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenLethalSilentDualExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenLethalSilentDualExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SilentDualExecution")
	float Damage = 1500.0f;
};
