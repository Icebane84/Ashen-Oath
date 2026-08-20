// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SerafinaBurnoutHUD.generated.h"

/**
 * UAshenUserWidget_SerafinaBurnoutHUD
 * UMG widget displaying Serafina's soul transference tether and burnout gauge.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SerafinaBurnoutHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float BurnoutPercentage = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsFeverCritical = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateBurnoutHUD(float Burnout, bool bFever);
};
