// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGenerativeFogDensityPhenotypeAdapter.generated.h"

/**
 * UAshenGenerativeFogDensityPhenotypeAdapter
 * Modulates volumetric fog density and sky tension based on WeatherTension.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGenerativeFogDensityPhenotypeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGenerativeFogDensityPhenotypeAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetVolumetricFogDensity() const { return VolumetricFogDensity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float VolumetricFogDensity = 0.02f;
};
