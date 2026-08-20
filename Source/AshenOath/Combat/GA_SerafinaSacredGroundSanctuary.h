// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaSacredGroundSanctuary.generated.h"

/**
 * UGA_SerafinaSacredGroundSanctuary
 *
 * Serafina's GAS consecrated ground ability healing allies and purging corruption in a 700u zone.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaSacredGroundSanctuary : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaSacredGroundSanctuary();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredGroundSanctuary")
	float HealAmount = 350.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SacredGroundSanctuary")
	float Radius = 700.0f;
};
