// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettPoisonSmokeGrid.generated.h"

/**
 * UGA_GarrettPoisonSmokeGrid
 *
 * Garrett's GAS ability deploying an expanded 600u poison grid dealing 300 damage and blinding enemies.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettPoisonSmokeGrid : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettPoisonSmokeGrid();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PoisonSmokeGrid")
	float Damage = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PoisonSmokeGrid")
	float GridRadius = 600.0f;
};
