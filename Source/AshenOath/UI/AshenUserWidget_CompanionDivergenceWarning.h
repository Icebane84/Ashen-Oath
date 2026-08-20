// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CompanionDivergenceWarning.generated.h"

/**
 * UAshenUserWidget_CompanionDivergenceWarning
 *
 * UMG backing widget warning when companion trust drops into critical divergence.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CompanionDivergenceWarning : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayCompanionDivergenceWarning(FName CompanionID, float TrustLevel);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateDivergenceWarning(FName CompanionID, float RiskPercent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName ActiveDivergentCompanionID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float ActiveTrustLevel = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedRiskPercentage = 0.0f;
};
