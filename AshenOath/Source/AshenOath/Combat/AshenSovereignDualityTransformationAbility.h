// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Combat/AshenGameplayAbility.h"
#include "Combat/AshenDualityTypes.h"
#include "AshenSovereignDualityTransformationAbility.generated.h"

/**
 * UAshenSovereignDualityTransformationAbility
 * 
 * Gameplay Ability executing Kaelen's real-time Light Mode <-> Dark Mode duality transformation.
 * Drives dynamic material instance parameters, corruption mask interpolation, radial pulse stagger, and visual/acoustic shift.
 */
UCLASS()
class ASHENOATH_API UAshenSovereignDualityTransformationAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenSovereignDualityTransformationAbility();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		bool bReplicateEndAbility,
		bool bWasCancelled) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float TransformationPulseRadius = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float PulsePoiseDamage = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float PulseBaseDamage = 85.0f;

	/** Executes end-to-end duality transformation pulse */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool TriggerDualityTransformationPulse();
};
