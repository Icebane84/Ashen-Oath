// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenUserWidget_IdentityCompilationSummaryHUD.generated.h"

/**
 * UAshenUserWidget_IdentityCompilationSummaryHUD
 * Displays summary of newly compiled StateVector, behavioral profiles, and trust shift indicators.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_IdentityCompilationSummaryHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FSoulStateVector DisplayedStateVector;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsSummaryVisible = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayCompilationSummary(const FSoulStateVector& InVector, bool bVisible);
};
