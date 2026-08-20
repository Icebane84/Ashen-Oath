// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenUserWidget_SomaticDialogueWarpHUD.generated.h"

/**
 * UAshenUserWidget_SomaticDialogueWarpHUD
 * 
 * UMG HUD Widget rendering violet ink corruption, parasitic whisper subtitles,
 * and text overwrite during Stage 3 / 4 Dysregulation dialogue interactions.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SomaticDialogueWarpHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_SomaticDialogueWarpHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates ink corruption visual intensity and glitch jitter */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Dialogue")
	void UpdateDialogueCorruption(float ParasitePressure, float InternalFriction);

	/** Sets the displayed dialogue text and the parasitic overlay text */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Dialogue")
	void SetDialogueTexts(const FText& InTrueText, const FText& InParasiticOverwrite);

	/** Updates the trigger squeeze fill ratio during a Will Struggle hold */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Dialogue")
	void UpdateSqueezeProgress(float CompletionRatio);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Dialogue")
	float GetCorruptionIntensity() const { return CurrentCorruptionIntensity; }

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Dialogue")
	float GetSqueezeRatio() const { return CurrentSqueezeRatio; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Dialogue")
	FText TrueText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Dialogue")
	FText ParasiticOverwritingText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Dialogue")
	float CurrentCorruptionIntensity = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Dialogue")
	float CurrentSqueezeRatio = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Dialogue")
	FLinearColor VioletInkColor = FLinearColor(0.45f, 0.05f, 0.75f, 1.0f);
};
