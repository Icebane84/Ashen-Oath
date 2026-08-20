// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettSmokeBombTrap.generated.h"

/**
 * UGA_GarrettSmokeBombTrap
 *
 * Garrett's smoke bomb proximity trap.
 * Spawns a smoke volume that blinds and slows enemies by 40% for 5s upon entering 350u.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettSmokeBombTrap : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettSmokeBombTrap();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData
	) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SmokeTrap")
	float TrapRadius = 350.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SmokeTrap")
	float SlowPercentage = 0.40f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SmokeTrap")
	float EffectDuration = 5.0f;
};
