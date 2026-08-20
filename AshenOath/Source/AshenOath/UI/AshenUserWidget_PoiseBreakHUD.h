// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_PoiseBreakHUD.generated.h"

/**
 * UAshenUserWidget_PoiseBreakHUD
 *
 * UMG backing widget rendering posture meter overlays on elite bosses and enemies.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PoiseBreakHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdatePoiseHUDDisplay(float CurrentPoise, float MaxPoise, bool bBroken);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedPoisePercent = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bDisplayedIsBroken = false;
};
