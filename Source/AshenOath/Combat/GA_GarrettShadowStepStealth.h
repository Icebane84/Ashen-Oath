// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettShadowStepStealth.generated.h"

/**
 * UGA_GarrettShadowStepStealth
 *
 * Garrett's shadow step stealth ability.
 * Grants 8.0s invisible stealth, +45% movement speed, and guarantees a critical hit on next strike.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettShadowStepStealth : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettShadowStepStealth();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ShadowStep")
	float StealthDuration = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ShadowStep")
	float SpeedBonusPercentage = 45.0f;
};
