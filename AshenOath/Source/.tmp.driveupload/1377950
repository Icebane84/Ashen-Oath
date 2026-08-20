// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettAssassinationExecution.generated.h"

/**
 * UGA_GarrettAssassinationExecution
 *
 * Garrett's stealth backstab execution dealing 850 damage and triggering trust accumulation.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettAssassinationExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettAssassinationExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|AssassinationExecution")
	float Damage = 850.0f;
};
