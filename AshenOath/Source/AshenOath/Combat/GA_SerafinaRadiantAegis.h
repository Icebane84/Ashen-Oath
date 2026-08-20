// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaRadiantAegis.generated.h"

/**
 * UGA_SerafinaRadiantAegis
 *
 * Serafina's protective holy light shield GAS ability.
 * Grants target character a 150 HP temporary barrier for 8 seconds,
 * absorbing incoming damage and poise depletion.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaRadiantAegis : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaRadiantAegis();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float BarrierAmount = 150.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float BarrierDuration = 8.0f;
};
