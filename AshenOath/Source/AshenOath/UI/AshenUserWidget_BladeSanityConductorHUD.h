// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenUserWidget_BladeSanityConductorHUD.generated.h"

/**
 * UAshenUserWidget_BladeSanityConductorHUD
 * 
 * Synchronized Somatosensory HUD displaying blade hunger crescent, sanity integrity gauge, and Quartz 6-stem spectrum visualizer.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BladeSanityConductorHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_BladeSanityConductorHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed convergence telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Convergence")
	void UpdateConvergenceHUD(const FBladeSanityHarmonicVector& Harmonics);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Convergence")
	FBladeSanityHarmonicVector DisplayedHarmonics;
};
