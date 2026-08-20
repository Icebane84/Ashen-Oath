// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenUserWidget_LensSelectionHUD.generated.h"

/**
 * UAshenUserWidget_LensSelectionHUD
 * In-Mindscape interactive lens selection widget displayed during integration.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LensSelectionHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EInterpretiveLens CurrentHighlightedLens = EInterpretiveLens::Grace;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsLensSelectionVisible = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayLensSelection(bool bVisible, bool bForcedCollapse);
};
