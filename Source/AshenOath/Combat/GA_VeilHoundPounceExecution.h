// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_VeilHoundPounceExecution.generated.h"

/**
 * UGA_VeilHoundPounceExecution
 *
 * Stealth pounce execution dealing 700 damage and pinning the target.
 */
UCLASS()
class ASHENOATH_API UGA_VeilHoundPounceExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_VeilHoundPounceExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PounceExecution")
	float BaseDamage = 700.0f;
};
