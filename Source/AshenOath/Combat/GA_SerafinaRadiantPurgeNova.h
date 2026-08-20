// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaRadiantPurgeNova.generated.h"

/**
 * UGA_SerafinaRadiantPurgeNova
 *
 * Serafina's radiant purge GAS ability dealing 500 Holy damage, healing 250 HP, and purging local corruption in a 800u radius.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaRadiantPurgeNova : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_SerafinaRadiantPurgeNova();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|RadiantPurgeNova")
	float Damage = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|RadiantPurgeNova")
	float HealAmount = 250.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|RadiantPurgeNova")
	float Radius = 800.0f;
};
