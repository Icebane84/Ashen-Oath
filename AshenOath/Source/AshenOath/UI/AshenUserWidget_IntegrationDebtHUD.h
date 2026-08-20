// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AI/AshenTraumaEnemyMatrixTypes.h"
#include "AshenUserWidget_IntegrationDebtHUD.generated.h"

/**
 * UAshenUserWidget_IntegrationDebtHUD
 * Diagnostic somatic HUD tracking active Integration Debt percentage and active degradation stage.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_IntegrationDebtHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedDebtPercent = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EIntegrationDebtStage DisplayedStage = EIntegrationDebtStage::Dormant;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateDebtHUD(float DebtPercent, EIntegrationDebtStage Stage);
};
