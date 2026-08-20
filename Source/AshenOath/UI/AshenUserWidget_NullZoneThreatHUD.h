// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_NullZoneThreatHUD.generated.h"

/**
 * UAshenUserWidget_NullZoneThreatHUD
 * HUD widget displaying Null Zone proximity meter, corruption intensity, and debt accumulation ticker.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_NullZoneThreatHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float ProximityMeter = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsWarningActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateThreatHUD(float Proximity, bool bWarning);
};
