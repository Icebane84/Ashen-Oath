// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenUserWidget_TraumaSomaticsHUD.generated.h"

/**
 * UAshenUserWidget_TraumaSomaticsHUD
 * 
 * UMG widget displaying Kaelen's real-time somatic metrics: Vein Corruption, Heart Rate BPM, and Blade Soot Heat.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TraumaSomaticsHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_TraumaSomaticsHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the somatic telemetry gauges */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Somatics")
	void UpdateSomaticsDisplay(
		ETraumaSomaticStage Stage,
		float VeinCorruption,
		float HeartBPM,
		float BladeSoot,
		int32 MicroNicks);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Somatics")
	ETraumaSomaticStage DisplayedStage = ETraumaSomaticStage::Stage0_BaselinePristine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Somatics")
	float DisplayedVeinCorruption = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Somatics")
	float DisplayedBPM = 60.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Somatics")
	float DisplayedBladeSoot = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Somatics")
	int32 DisplayedNicks = 0;
};
