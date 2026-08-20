// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTraumaPostProcessComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTraumaVisualsUpdatedSignature, float, ChromaticAberration, float, VignetteIntensity);

/**
 * UAshenTraumaPostProcessComponent
 *
 * Modulates player camera post-process settings (lens chromatic aberration 0.0 -> 1.5,
 * vignette intensity 0.0 -> 0.8) based on Trauma Matrix accumulated damage.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaPostProcessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTraumaPostProcessComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Trauma")
	void SetTraumaLevel(float NewTrauma);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Trauma")
	float CurrentTraumaLevel = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Trauma")
	float TargetChromaticAberration = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Trauma")
	float TargetVignetteIntensity = 0.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Trauma|Events")
	FOnTraumaVisualsUpdatedSignature OnTraumaVisualsUpdated;

private:
	float CurrentChromaticAberration = 0.0f;
	float CurrentVignetteIntensity = 0.0f;
};
