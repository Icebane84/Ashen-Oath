// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaSanctuaryAuraExecution.generated.h"

/**
 * UGA_SerafinaSanctuaryAuraExecution
 *
 * Serafina's GAS ability deploying a 700u protective sanctuary aura absorbing 800 damage and restoring stamina.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaSanctuaryAuraExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaSanctuaryAuraExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SanctuaryAuraExecution")
	float DamageAbsorbed = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SanctuaryAuraExecution")
	float Radius = 700.0f;
};
