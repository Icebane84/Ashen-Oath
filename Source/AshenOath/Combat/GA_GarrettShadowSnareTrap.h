// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettShadowSnareTrap.generated.h"

/**
 * UGA_GarrettShadowSnareTrap
 *
 * Garrett's tactical trap GAS ability deploying a shadow snare immobilizing targets for 4.0s and inflicting 200 Physical damage.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettShadowSnareTrap : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettShadowSnareTrap();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ShadowSnare")
	float SnareDamage = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|ShadowSnare")
	float TrapRadius = 350.0f;
};
