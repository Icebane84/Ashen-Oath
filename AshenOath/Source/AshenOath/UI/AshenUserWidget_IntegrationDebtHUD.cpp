// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_IntegrationDebtHUD.h"

void UAshenUserWidget_IntegrationDebtHUD::UpdateDebtHUD(float DebtPercent, EIntegrationDebtStage Stage)
{
	DisplayedDebtPercent = DebtPercent;
	DisplayedStage = Stage;

	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_IntegrationDebtHUD: Integration Debt: %.1f%% (Stage: %d)"),
		DisplayedDebtPercent, static_cast<int32>(DisplayedStage));
}
