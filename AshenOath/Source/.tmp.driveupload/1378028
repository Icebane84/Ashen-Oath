// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenEldrinsGambitAbility.generated.h"

/**
 * UGA_KaelenEldrinsGambitAbility
 *
 * Kaelen's ultimate high-risk GAS ability engaging Eldrin's consciousness within Oathbringer to reverse a fatal blow at the cost of 40 Integration Debt.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenEldrinsGambitAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenEldrinsGambitAbility();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|EldrinsGambit")
	float IntegrationDebtCost = 40.0f;
};
