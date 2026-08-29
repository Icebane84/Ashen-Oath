// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "AshenMindscapeSpectralDioramaComponent.generated.h"

/**
 * UAshenMindscapeSpectralDioramaComponent
 * 
 * Controls spatial 3D holographic spectral figures inside the Memory Palace, advancing timeline scrubbing and triggering voice-acted reenactment sequences.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMindscapeSpectralDioramaComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMindscapeSpectralDioramaComponent();

	/** Scrubs timeline through memory reenactment */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Mindscape")
	void ScrubTimeline(float NormalizedTime);

	UFUNCTION(BlueprintPure, Category = "Ashen|Mindscape")
	float GetCurrentTimelinePosition() const { return CurrentScrubTime; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Mindscape")
	bool IsReenactmentActive() const { return bReenactmentActive; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Mindscape")
	float CurrentScrubTime = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Mindscape")
	bool bReenactmentActive = false;
};
