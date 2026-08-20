// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_VeilHoundAmbushHUD.generated.h"

/**
 * UAshenUserWidget_VeilHoundAmbushHUD
 *
 * UMG backing widget rendering visual telemetry for stealth detection distance and pack frenzy.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_VeilHoundAmbushHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateVeilHoundHUDDisplay(bool bStealthed, float PounceMultiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bDisplayedIsStealthed = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedPounceMultiplier = 1.0f;
};
