// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ResonanceSyncHUD.generated.h"

/**
 * UAshenUserWidget_ResonanceSyncHUD
 * HUD widget displaying active Resonance Sync window, damage boost multiplier (+15%), and remaining surge duration.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ResonanceSyncHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsResonanceSyncActive = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DurationRemaining = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayResonanceSync(bool bActive, float InDuration);
};
