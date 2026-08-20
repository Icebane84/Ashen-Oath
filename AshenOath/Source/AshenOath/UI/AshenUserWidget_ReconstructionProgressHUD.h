// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ReconstructionProgressHUD.generated.h"

/**
 * UAshenUserWidget_ReconstructionProgressHUD
 * Somatic HUD displaying active psychic reconstruction progress percentage and Resolve cost per second.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ReconstructionProgressHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float ProgressPercent = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsActivelyReconstructing = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateProgress(float InProgress, bool bActive);
};
