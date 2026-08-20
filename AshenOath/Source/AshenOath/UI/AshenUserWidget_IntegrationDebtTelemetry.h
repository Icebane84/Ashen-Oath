// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenUserWidget_IntegrationDebtTelemetry.generated.h"

/**
 * UAshenUserWidget_IntegrationDebtTelemetry
 * UMG widget presenting live debt telemetry, stage indicators, and warning flashes during Runtime Noise.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_IntegrationDebtTelemetry : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedDebt = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EAshenIntegrationDebtStage DisplayedStage = EAshenIntegrationDebtStage::Stable;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshDebtTelemetry(float Debt, EAshenIntegrationDebtStage Stage);
};
