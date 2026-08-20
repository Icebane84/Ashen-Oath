// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenDiegeticCameraTraumaShakeModulator.generated.h"

/**
 * UAshenDiegeticCameraTraumaShakeModulator
 * Binds camera trauma micro-shakes to IntegrationDebt and Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticCameraTraumaShakeModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticCameraTraumaShakeModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Camera")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Camera")
	float GetCameraTraumaScalar() const { return CameraTraumaScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Camera")
	float CameraTraumaScalar = 0.0f;
};
