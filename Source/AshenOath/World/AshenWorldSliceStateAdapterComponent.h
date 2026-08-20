// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenWorldSliceStateAdapterComponent.generated.h"

/**
 * UAshenWorldSliceStateAdapterComponent
 *
 * Modular World Slice adapter.
 * Submits environmental imprints and consumes FSoulStateVector invalidation pulses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWorldSliceStateAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWorldSliceStateAdapterComponent();

	/** Submits environmental trauma imprint */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|WorldSlice")
	void SubmitEnvironmentalImprint(float CorruptionTrauma);

	/** Callback when canonical FSoulStateVector invalidates */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|WorldSlice")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	/** Returns weather tension scalar */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|WorldSlice")
	float GetWeatherTension() const { return WeatherTension; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|WorldSlice")
	float WeatherTension = 0.0f;
};
