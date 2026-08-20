// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_VirtueFractureHUD.generated.h"

/**
 * UAshenUserWidget_VirtueFractureHUD
 *
 * UMG backing widget rendering virtue fracture decay metrics.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_VirtueFractureHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateVirtueFractureHUDDisplay(FName VirtueID, float FractureLevelPercent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName ActiveVirtueID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float ActiveFracturePercent = 0.0f;
};
