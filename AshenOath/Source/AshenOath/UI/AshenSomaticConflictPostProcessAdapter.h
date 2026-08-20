// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenSomaticConflictPostProcessAdapter.generated.h"

class APostProcessVolume;

/**
 * UAshenSomaticConflictPostProcessAdapter
 * 
 * Dynamic post-process controller mapping Internal Friction (Phi_internal) to:
 * - Chromatic Aberration (0.0 to 3.5)
 * - Vignette Intensity (0.2 to 0.85)
 * - Radial Screen Distortion
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticConflictPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticConflictPostProcessAdapter();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Updates the target post process intensities from somatic friction */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|PostProcess")
	void UpdateFrictionPostProcess(float InternalFriction);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|PostProcess")
	float GetCurrentChromaticAberration() const { return CurrentChromaticAberration; }

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|PostProcess")
	float GetCurrentVignette() const { return CurrentVignette; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|PostProcess")
	float MaxChromaticAberration = 3.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|PostProcess")
	float MaxVignetteIntensity = 0.85f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|PostProcess")
	float InterpSpeed = 5.0f;

private:
	float CurrentChromaticAberration = 0.0f;
	float TargetChromaticAberration = 0.0f;

	float CurrentVignette = 0.2f;
	float TargetVignette = 0.2f;
};
