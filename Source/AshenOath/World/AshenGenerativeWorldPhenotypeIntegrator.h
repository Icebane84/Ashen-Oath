// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGenerativeWorldPhenotypeIntegrator.generated.h"

/**
 * UAshenGenerativeWorldPhenotypeIntegrator
 * Connects generative world state component to FSoulStateVector invalidations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGenerativeWorldPhenotypeIntegrator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGenerativeWorldPhenotypeIntegrator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetWeatherTension() const { return WeatherTension; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float WeatherTension = 0.0f;
};
