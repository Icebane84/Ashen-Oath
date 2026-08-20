// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SympatheticTetherHUD.generated.h"

/**
 * UAshenUserWidget_SympatheticTetherHUD
 * Visual link displaying the ethereal damage reflection tether between Kaelen and Serafina during Guilt-Stitcher encounters.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SympatheticTetherHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsTetherVisible = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float TetherTension = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateTetherState(bool bActive, float Tension);
};
