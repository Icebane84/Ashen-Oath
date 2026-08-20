// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenOathBurnExecution.generated.h"

/**
 * UGA_KaelenOathBurnExecution
 *
 * Kaelen's ultimate high-risk Oath Burn execution slam.
 * Burns 50% max HP/Oath gauge to deal 650 Physical/Holy damage in a 450u forward arc.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenOathBurnExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenOathBurnExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|OathBurnExecution")
	float Damage = 650.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|OathBurnExecution")
	float Radius = 450.0f;
};
