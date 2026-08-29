// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "World/AshenDestructionWeatherAITypes.h"
#include "AshenUserWidget_DestructionWeatherAIHUD.generated.h"

/**
 * UAshenUserWidget_DestructionWeatherAIHUD
 * 
 * Tactical HUD widget displaying dynamic lock-on range rings, atmospheric visibility meters, and conductive lightning hazard warnings.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DestructionWeatherAIHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_DestructionWeatherAIHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed tactical telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Convergence")
	void UpdateTacticalHUD(
		EAtmosphericVisibilityTier VisibilityTier,
		float LockOnRangeUU,
		bool bConductiveSurfaceNearby,
		bool bStealthAmbushEligible);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Convergence")
	EAtmosphericVisibilityTier DisplayedTier = EAtmosphericVisibilityTier::ClearDaylight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Convergence")
	float DisplayedLockOnRange = 1500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Convergence")
	bool bDisplayedConductiveWarning = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Convergence")
	bool bDisplayedStealthEligible = false;
};
