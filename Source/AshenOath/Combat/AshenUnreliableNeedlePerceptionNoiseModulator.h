// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUnreliableNeedlePerceptionNoiseModulator.generated.h"

/**
 * UAshenUnreliableNeedlePerceptionNoiseModulator
 * Modulates Layer III perception noise on Kaelen's HUD.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNeedlePerceptionNoiseModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenUnreliableNeedlePerceptionNoiseModulator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	float GetNeedleNoiseIntensity() const { return NeedleNoiseIntensity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|UI")
	float NeedleNoiseIntensity = 0.0f;
};
