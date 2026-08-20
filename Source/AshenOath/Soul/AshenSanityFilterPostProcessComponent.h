// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanityFilterPostProcessComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSanityFilterUpdatedSignature, float, DistortionIntensity);

/**
 * UAshenSanityFilterPostProcessComponent
 *
 * Dynamically adjusts post-processing settings (Vignette, Chromatic Aberration, Saturation)
 * based on current player Sanity %. Higher insanity increases visual distortion.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanityFilterPostProcessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanityFilterPostProcessComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SanityFilter")
	void UpdateFilterFromSanity(float CurrentSanity, float MaxSanity);

	UFUNCTION(BlueprintPure, Category = "AshenOath|SanityFilter")
	float GetCurrentDistortionIntensity() const { return DistortionIntensity; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SanityFilter")
	float MaxVignetteIntensity = 0.8f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SanityFilter")
	float MaxChromaticAberration = 4.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SanityFilter|Events")
	FOnSanityFilterUpdatedSignature OnSanityFilterUpdated;

private:
	float DistortionIntensity = 0.0f;
};
