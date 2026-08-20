// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettExplosiveFlashPowder.generated.h"

/**
 * UGA_GarrettExplosiveFlashPowder
 *
 * Garrett's tactical offensive flash powder burst ability.
 * Deals 160 Fire damage and blinds all targets in a 350u radius for 4.0 seconds.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettExplosiveFlashPowder : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettExplosiveFlashPowder();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|FlashPowder")
	float Damage = 160.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|FlashPowder")
	float BurstRadius = 350.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|FlashPowder")
	float BlindDuration = 4.0f;
};
