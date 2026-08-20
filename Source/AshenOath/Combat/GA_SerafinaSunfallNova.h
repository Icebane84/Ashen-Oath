// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaSunfallNova.generated.h"

/**
 * UGA_SerafinaSunfallNova
 *
 * Serafina's ultimate GAS ability invoking a 1000u solar blast dealing 650 Holy damage and blinding all nearby Corrupted enemies.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaSunfallNova : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaSunfallNova();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SunfallNova")
	float Damage = 650.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SunfallNova")
	float Radius = 1000.0f;
};
