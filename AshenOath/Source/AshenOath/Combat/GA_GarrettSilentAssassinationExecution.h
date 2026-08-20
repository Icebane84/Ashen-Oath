// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettSilentAssassinationExecution.generated.h"

/**
 * UGA_GarrettSilentAssassinationExecution
 *
 * Garrett's peak-resonance silent backstab execution dealing 1200 damage.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettSilentAssassinationExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettSilentAssassinationExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SilentAssassinationExecution")
	float Damage = 1200.0f;
};
