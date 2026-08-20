// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenNonBinaryMoralitySubsystem.h"
#include "AshenUserWidget_NonBinaryMoralityHUD.generated.h"

/**
 * UAshenUserWidget_NonBinaryMoralityHUD
 *
 * UMG backing widget displaying character disposition vectors (Protective vs Vengeful).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_NonBinaryMoralityHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateMoralityHUDDisplay(EAshenMoralDisposition Disposition, float Magnitude);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	EAshenMoralDisposition DisplayedDisposition = EAshenMoralDisposition::Protective;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedMagnitude = 0.0f;
};
