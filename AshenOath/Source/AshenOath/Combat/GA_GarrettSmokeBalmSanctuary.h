// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettSmokeBalmSanctuary.generated.h"

/**
 * UGA_GarrettSmokeBalmSanctuary
 *
 * Garrett's GAS support ability deploying a 500u smoke balm cloud granting stealth and health regeneration.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettSmokeBalmSanctuary : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettSmokeBalmSanctuary();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SmokeBalmSanctuary")
	float HealPerSecond = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SmokeBalmSanctuary")
	float Radius = 500.0f;
};
