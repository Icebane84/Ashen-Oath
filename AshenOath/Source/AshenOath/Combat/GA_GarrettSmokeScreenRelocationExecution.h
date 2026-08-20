// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettSmokeScreenRelocationExecution.generated.h"

/**
 * UGA_GarrettSmokeScreenRelocationExecution
 *
 * Garrett's GAS ability deploying a 400u smoke screen and teleporting/relocating behind cover.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettSmokeScreenRelocationExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettSmokeScreenRelocationExecution();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SmokeScreenRelocation")
	float SmokeRadius = 400.0f;
};
