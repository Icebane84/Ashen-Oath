// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "AshenUserWidget_WordlessResonancePromptHUD.generated.h"

/**
 * UAshenUserWidget_WordlessResonancePromptHUD
 * 
 * Subtle gold/amber vignette flare that pulses on screen edge when a companion
 * commits to a Shoulder-To-Shoulder charge.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WordlessResonancePromptHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_WordlessResonancePromptHUD(const FObjectInitializer& ObjectInitializer);

	/** Activates resonance pulse */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Resonance")
	void TriggerResonancePulse(FName CompanionName, float PulseIntensity = 1.0f);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Resonance")
	bool IsPulseActive() const { return bActive; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Resonance")
	FName ActiveCompanionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Resonance")
	float Intensity = 0.0f;

private:
	bool bActive = false;
};
