// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaAegisShield.generated.h"

/**
 * UGA_SerafinaAegisShield
 *
 * Serafina's radiant barrier ability.
 * Grants a 300 HP radiant shield to allies within 500 units for 8 seconds.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaAegisShield : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaAegisShield();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Shield")
	float ShieldAmount = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Shield")
	float ShieldRadius = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Shield")
	float ShieldDuration = 8.0f;
};
