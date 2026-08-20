// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_FinisherWeakspotHUD.generated.h"

/**
 * UAshenUserWidget_FinisherWeakspotHUD
 * Displays the 2.5x Flank Damage Multiplier reticle, exposed weakspot outline, and vulnerability timer.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_FinisherWeakspotHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsWeakspotExposed = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float ExposureTimeRemaining = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayFlankWeakspot(bool bExposed, float Duration);
};
