// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenUserWidget_CompassAstrolabeHUD.generated.h"

/**
 * UAshenUserWidget_CompassAstrolabeHUD
 * Minimalist brass compass astrolabe widget rendering sanctuary bearings and magnetic resonance states.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CompassAstrolabeHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayNeedleDegrees = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	ECompassResonanceState DisplayState = ECompassResonanceState::Dormant;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateAstrolabeDisplay(float InDegrees, ECompassResonanceState InState);
};
