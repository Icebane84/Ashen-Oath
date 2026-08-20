// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaSacredBarrierExecution.generated.h"

/**
 * UGA_SerafinaSacredBarrierExecution
 *
 * Serafina's ultimate GAS barrier absorbing 1000 damage and purging audio/visual distortion in a 600u radius.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaSacredBarrierExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaSacredBarrierExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredBarrierExecution")
	float ShieldAbsorbAmount = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredBarrierExecution")
	float Radius = 600.0f;
};
