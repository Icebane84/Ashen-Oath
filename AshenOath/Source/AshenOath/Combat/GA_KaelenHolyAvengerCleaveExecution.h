// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenHolyAvengerCleaveExecution.generated.h"

/**
 * UGA_KaelenHolyAvengerCleaveExecution
 *
 * Kaelen's high-morale Holy cleave dealing 1400 damage in an 800u cone.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenHolyAvengerCleaveExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenHolyAvengerCleaveExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|HolyAvengerCleave")
	float Damage = 1400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|HolyAvengerCleave")
	float Radius = 800.0f;
};
