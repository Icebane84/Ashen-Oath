// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCollapseAudioVisualDistorterComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCollapseDistortionUpdatedSignature, float, DistortionIntensity, float, AudioLowPassFreq);

/**
 * UAshenCollapseAudioVisualDistorterComponent
 *
 * Modulates screen chromatic distortion, visual lens noise, and pitch-bent audio low-pass filters
 * during involuntary Mindscape Stage 1-4 collapse events.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCollapseAudioVisualDistorterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCollapseAudioVisualDistorterComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Distortion")
	void UpdateCollapseDistortion(int32 CollapseStage);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Distortion")
	float CurrentDistortionIntensity = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Distortion")
	float CurrentAudioLowPassFreq = 20000.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Distortion|Events")
	FOnCollapseDistortionUpdatedSignature OnDistortionUpdated;
};
