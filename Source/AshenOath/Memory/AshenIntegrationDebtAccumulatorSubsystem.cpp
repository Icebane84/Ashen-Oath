// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenIntegrationDebtAccumulatorSubsystem.h"

void UAshenIntegrationDebtAccumulatorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenIntegrationDebtAccumulatorSubsystem: Fast-moving pressure accumulator initialized."));
}

void UAshenIntegrationDebtAccumulatorSubsystem::AccumulateDebt(float DebtDelta)
{
	CurrentDebt = FMath::Clamp(CurrentDebt + DebtDelta, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenIntegrationDebtAccumulatorSubsystem: Debt pressure updated (Delta: %.2f | Current: %.2f)"),
		DebtDelta, CurrentDebt);
}
