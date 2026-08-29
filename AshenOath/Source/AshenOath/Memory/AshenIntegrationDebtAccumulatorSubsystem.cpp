// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenIntegrationDebtAccumulatorSubsystem.h"
#include "Memory/AshenMemoryBattleSubsystem.h"
#include "Engine/World.h"

void UAshenIntegrationDebtAccumulatorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentDebt = 0.0f;
	CurrentStage = EAshenIntegrationDebtStage::Stable;
	BalanceDataAsset = nullptr;
}

void UAshenIntegrationDebtAccumulatorSubsystem::AccumulateDebt(float DebtDelta)
{
	if (DebtDelta <= 0.0f)
	{
		return;
	}

	CurrentDebt = FMath::Clamp(CurrentDebt + DebtDelta, 0.0f, 1.0f);
	EvaluateStageTransition();
}

void UAshenIntegrationDebtAccumulatorSubsystem::RelieveDebt(float DebtRelief)
{
	if (DebtRelief <= 0.0f)
	{
		return;
	}

	CurrentDebt = FMath::Clamp(CurrentDebt - DebtRelief, 0.0f, 1.0f);
	EvaluateStageTransition();
}

void UAshenIntegrationDebtAccumulatorSubsystem::ClearAllDebt()
{
	CurrentDebt = 0.0f;
	EvaluateStageTransition();
}

void UAshenIntegrationDebtAccumulatorSubsystem::SetIntegrationDebt(float NewDebt)
{
	CurrentDebt = FMath::Clamp(NewDebt, 0.0f, 1.0f);
	EvaluateStageTransition();
}

float UAshenIntegrationDebtAccumulatorSubsystem::GetEffectiveParryWindow() const
{
	FIntegrationDebtPenalties Penalties;
	if (BalanceDataAsset)
	{
		Penalties = BalanceDataAsset->GetClampedPenalties();
	}
	else
	{
		Penalties.DefaultParryWindowSeconds = 0.20f;
		Penalties.DegradedParryWindowSeconds = 0.12f;
	}

	if (CurrentStage == EAshenIntegrationDebtStage::RuntimeNoise || CurrentStage == EAshenIntegrationDebtStage::ForcedCollapse)
	{
		return Penalties.DegradedParryWindowSeconds; // 0.12s
	}

	return Penalties.DefaultParryWindowSeconds; // 0.20s
}

void UAshenIntegrationDebtAccumulatorSubsystem::EvaluateStageTransition()
{
	FIntegrationDebtStageThresholds Thresholds;
	if (BalanceDataAsset)
	{
		Thresholds = BalanceDataAsset->GetClampedThresholds();
	}
	else
	{
		Thresholds.MemoryBleedThreshold = 0.50f;
		Thresholds.RuntimeNoiseThreshold = 0.75f;
		Thresholds.ForcedCollapseThreshold = 1.00f;
	}

	EAshenIntegrationDebtStage NewStage = EAshenIntegrationDebtStage::Stable;
	if (CurrentDebt >= Thresholds.ForcedCollapseThreshold)
	{
		NewStage = EAshenIntegrationDebtStage::ForcedCollapse;
	}
	else if (CurrentDebt >= Thresholds.RuntimeNoiseThreshold)
	{
		NewStage = EAshenIntegrationDebtStage::RuntimeNoise;
	}
	else if (CurrentDebt >= Thresholds.MemoryBleedThreshold)
	{
		NewStage = EAshenIntegrationDebtStage::MemoryBleed;
	}
	else if (CurrentDebt >= 0.25f)
	{
		NewStage = EAshenIntegrationDebtStage::LatentPressure;
	}

	const bool bStageChanged = (NewStage != CurrentStage);
	CurrentStage = NewStage;

	if (bStageChanged && OnIntegrationDebtStageChanged.IsBound())
	{
		OnIntegrationDebtStageChanged.Broadcast(CurrentStage, CurrentDebt);
	}

	// If ForcedCollapse reached (100%), trigger immediate in-situ Mindscape Memory Battle
	if (CurrentStage == EAshenIntegrationDebtStage::ForcedCollapse)
	{
		UE_LOG(LogTemp, Error, TEXT("UAshenIntegrationDebtAccumulatorSubsystem: *** FORCED PSYCHOLOGICAL COLLAPSE (Debt: 100%%) *** — Initiating In-Situ Mindscape Memory Battle!"));

		if (UWorld* World = GetWorld())
		{
			if (UAshenMemoryBattleSubsystem* BattleSubsystem = World->GetSubsystem<UAshenMemoryBattleSubsystem>())
			{
				// Initiate forced memory battle
				BattleSubsystem->InitiateMemoryBattle(FName(TEXT("ForcedMindscapeCollapse")), 1.0f, true);
			}
		}
	}
}
