// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_MindscapeFractureMapHUD.generated.h"

/**
 * UAshenUserWidget_MindscapeFractureMapHUD
 * UMG backing widget presenting mindscape node connections and instability indicators.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MindscapeFractureMapHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float MapInstabilityPercent = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateFractureMapDisplay(float NewInstabilityIndex);
};
