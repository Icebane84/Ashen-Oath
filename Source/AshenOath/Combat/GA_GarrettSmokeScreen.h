// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettSmokeScreen.generated.h"

/**
 * UGA_GarrettSmokeScreen
 *
 * Garrett's tactical smoke screen grenade.
 * Deploys a smoke volume that resets enemy threat and grants 6 seconds of stealth to allies inside 500 units.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettSmokeScreen : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettSmokeScreen();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SmokeScreen")
	float SmokeRadius = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SmokeScreen")
	float StealthDuration = 6.0f;
};
