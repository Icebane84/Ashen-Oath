// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_MarginaliaCrossoutOverlayHUD.generated.h"

/**
 * UAshenUserWidget_MarginaliaCrossoutOverlayHUD
 * 
 * Renders animated violent strike-through lines and heavy charcoal scratch-outs
 * across targeted paragraphs when Garrett or Kaelen reject an entry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MarginaliaCrossoutOverlayHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_MarginaliaCrossoutOverlayHUD(const FObjectInitializer& ObjectInitializer);

	/** Plays animated scratch-out strike */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Crossout")
	void TriggerCrossoutAnimation(const FString& TargetEntryId, float CrossoutIntensity = 1.0f);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Crossout")
	float GetIntensity() const { return Intensity; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Crossout")
	FString TargetId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Crossout")
	float Intensity = 1.0f;
};
