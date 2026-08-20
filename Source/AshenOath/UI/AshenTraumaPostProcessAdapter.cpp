// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenTraumaPostProcessAdapter.h"

UAshenTraumaPostProcessAdapter::UAshenTraumaPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTraumaPostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenTraumaPostProcessAdapter::ApplyDebtPostProcess(EIntegrationDebtStage Stage, float DebtPercent)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenTraumaPostProcessAdapter: Applied Debt Post-Process -> Stage: %d, Debt: %.1f%%"),
		static_cast<int32>(Stage), DebtPercent);
}
