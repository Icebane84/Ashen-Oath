// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGenerativeEclipseSkyAtmosphereAdapter.generated.h"

/**
 * UAshenGenerativeEclipseSkyAtmosphereAdapter
 * Modulates sky atmosphere Rayleigh scattering based on Dissonance.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGenerativeEclipseSkyAtmosphereAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGenerativeEclipseSkyAtmosphereAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetRayleighScatteringScale() const { return RayleighScatteringScale; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float RayleighScatteringScale = 1.0f;
};
