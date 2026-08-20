// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettAssassinationSmokebombExecution.generated.h"

/**
 * UGA_GarrettAssassinationSmokebombExecution
 *
 * Garrett's ultimate stealth smokebomb execution dealing 1100 damage in a 400u radius.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettAssassinationSmokebombExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettAssassinationSmokebombExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|AssassinationSmokebombExecution")
	float Damage = 1100.0f;
};
