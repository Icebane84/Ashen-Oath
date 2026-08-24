// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Audio/AshenQuartzAudioTypes.h"
#include "AshenUserWidget_QuartzStemMatrixHUD.generated.h"

/**
 * UAshenUserWidget_QuartzStemMatrixHUD
 * 
 * UMG widget displaying the 6-stem dynamic audio levels, 115 BPM metronome flash, Flow state indicator, and active alchemical filters.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_QuartzStemMatrixHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_QuartzStemMatrixHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates HUD with live stem matrix data */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Quartz")
	void UpdateStemMatrixHUD(const FQuartzStemMatrixState& State);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Quartz")
	FQuartzStemMatrixState DisplayedMatrixState;
};
