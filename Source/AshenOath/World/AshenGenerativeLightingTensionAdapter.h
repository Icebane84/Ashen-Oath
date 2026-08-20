// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGenerativeLightingTensionAdapter.generated.h"

/**
 * UAshenGenerativeLightingTensionAdapter
 * Modulates directional sky light intensity and shadow sharpness based on WeatherTension.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGenerativeLightingTensionAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGenerativeLightingTensionAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetSkyLightIntensityScalar() const { return SkyLightIntensityScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float SkyLightIntensityScalar = 1.0f;
};
