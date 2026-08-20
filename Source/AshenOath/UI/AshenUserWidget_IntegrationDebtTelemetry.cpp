// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_IntegrationDebtTelemetry.h"

void UAshenUserWidget_IntegrationDebtTelemetry::RefreshDebtTelemetry(float Debt, EAshenIntegrationDebtStage Stage)
{
	DisplayedDebt = Debt;
	DisplayedStage = Stage;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_IntegrationDebtTelemetry: Telemetry refreshed — Debt: %.2f | Stage: %d"), DisplayedDebt, (int32)DisplayedStage);
}
