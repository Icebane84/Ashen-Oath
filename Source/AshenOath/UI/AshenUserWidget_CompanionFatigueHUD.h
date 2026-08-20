// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CompanionFatigueHUD.generated.h"

/**
 * UAshenUserWidget_CompanionFatigueHUD
 * HUD widget displaying Tripartite Fatigue bars for Garrett, Serafina, and Kaelen.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CompanionFatigueHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float GarrettFatigue = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float SerafinaFatigue = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float KaelenFatigue = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateFatigueHUD(float InGFatigue, float InSFatigue, float InKFatigue);
};
