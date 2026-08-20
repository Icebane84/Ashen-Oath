// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticLocomotionPostureComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLocomotionPostureChangedSignature, float, PostureLimpBlend, float, SpeedMultiplier);

/**
 * UAshenDiegeticLocomotionPostureComponent
 *
 * Locomotion posture component adjusting movement speed and posture blending based on injury/fatigue.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticLocomotionPostureComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticLocomotionPostureComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|LocomotionPosture")
	void UpdateLocomotionPosture(float CurrentHealth, float MaxHealth, float FatiguePercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|LocomotionPosture|Events")
	FOnLocomotionPostureChangedSignature OnPostureChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|LocomotionPosture")
	float CalculatedLimpBlend = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|LocomotionPosture")
	float CalculatedSpeedMultiplier = 1.0f;
};
