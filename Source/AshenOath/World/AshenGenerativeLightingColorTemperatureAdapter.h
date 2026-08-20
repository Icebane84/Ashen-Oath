// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGenerativeLightingColorTemperatureAdapter.generated.h"

/**
 * UAshenGenerativeLightingColorTemperatureAdapter
 * Shifts atmospheric sun color temperature based on IntegrationDebt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGenerativeLightingColorTemperatureAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGenerativeLightingColorTemperatureAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetSunColorTemperatureKelvin() const { return SunColorTemperatureKelvin; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float SunColorTemperatureKelvin = 6500.0f;
};
