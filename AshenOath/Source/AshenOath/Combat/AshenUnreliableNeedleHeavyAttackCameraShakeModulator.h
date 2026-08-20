// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUnreliableNeedleHeavyAttackCameraShakeModulator.generated.h"

/**
 * UAshenUnreliableNeedleHeavyAttackCameraShakeModulator
 * Modulates camera shake magnitude during heavy attacks based on Isolation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNeedleHeavyAttackCameraShakeModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenUnreliableNeedleHeavyAttackCameraShakeModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetCameraShakeMagnitudeMultiplier() const { return CameraShakeMagnitudeMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float CameraShakeMagnitudeMultiplier = 1.0f;
};
