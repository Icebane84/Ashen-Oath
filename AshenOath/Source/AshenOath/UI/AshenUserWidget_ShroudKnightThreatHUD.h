// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ShroudKnightThreatHUD.generated.h"

/**
 * UAshenUserWidget_ShroudKnightThreatHUD
 * Paranoia threat meter and elite poise shield indicator.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ShroudKnightThreatHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float ParanoiaMeterRatio = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsShroudPhasing = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateThreatHUD(float ParanoiaRatio, bool bPhasing);
};
