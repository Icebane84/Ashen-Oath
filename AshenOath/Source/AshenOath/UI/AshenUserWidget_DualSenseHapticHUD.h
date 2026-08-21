// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "AshenUserWidget_DualSenseHapticHUD.generated.h"

/**
 * UAshenUserWidget_DualSenseHapticHUD
 * 
 * UMG/Slate widget displaying real-time adaptive trigger state, vibration levels,
 * and controller speaker audio output.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_DualSenseHapticHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_DualSenseHapticHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the displayed trigger telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Haptics")
	void UpdateTriggerDisplay(const FDualSenseTriggerConfig& Left, const FDualSenseTriggerConfig& Right);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Haptics")
	float GetLeftResistance() const { return DisplayedLeftResistance; }

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Haptics")
	float GetRightResistance() const { return DisplayedRightResistance; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Haptics")
	float DisplayedLeftResistance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Haptics")
	float DisplayedRightResistance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Haptics")
	bool bIsLockoutActive = false;
};
