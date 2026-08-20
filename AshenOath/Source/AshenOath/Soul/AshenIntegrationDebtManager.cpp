// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenIntegrationDebtManager.h"
#include "Soul/AshenSoulConstellationSubsystem.h"
#include "Engine/GameInstance.h"

void UAshenIntegrationDebtManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenIntegrationDebtManager: 4-stage debt escalation manager initialized."));
}

void UAshenIntegrationDebtManager::Deinitialize() { Super::Deinitialize(); }

void UAshenIntegrationDebtManager::UpdateIntegrationDebt(float DebtDelta)
{
	const float PrevDebt = CurrentIntegrationDebt;
	const EAshenIntegrationDebtStage PrevStage = CurrentDebtStage;

	CurrentIntegrationDebt = FMath::Clamp(CurrentIntegrationDebt + DebtDelta, 0.0f, 1.5f);
	CurrentDebtStage = EvaluateDebtStage(CurrentIntegrationDebt);

	if (CurrentDebtStage != PrevStage && OnDebtStageEscalated.IsBound())
	{
		OnDebtStageEscalated.Broadcast(PrevStage, CurrentDebtStage);
		UE_LOG(LogTemp, Warning, TEXT("UAshenIntegrationDebtManager: Debt stage escalated from %d to %d (Debt: %f)"),
			(int32)PrevStage, (int32)CurrentDebtStage, CurrentIntegrationDebt);
	}

	if (CurrentIntegrationDebt >= 1.0f && OnForcedCollapseThresholdReached.IsBound())
	{
		OnForcedCollapseThresholdReached.Broadcast(CurrentIntegrationDebt);
		UE_LOG(LogTemp, Error, TEXT("UAshenIntegrationDebtManager: FORCED COLLAPSE THRESHOLD REACHED (%f)"), CurrentIntegrationDebt);
	}
}

EAshenIntegrationDebtStage UAshenIntegrationDebtManager::EvaluateDebtStage(float DebtValue) const
{
	if (DebtValue >= 1.0f)  return EAshenIntegrationDebtStage::ForcedCollapse;
	if (DebtValue >= 0.75f) return EAshenIntegrationDebtStage::RuntimeNoise;
	if (DebtValue >= 0.50f) return EAshenIntegrationDebtStage::MemoryBleed;
	if (DebtValue >= 0.25f) return EAshenIntegrationDebtStage::LatentPressure;
	return EAshenIntegrationDebtStage::Stable;
}

float UAshenIntegrationDebtManager::GetParryWindowMultiplier() const
{
	// ENGINE-SPEC-001 Section 2: Runtime Noise narrows parry window by 15% (0.85 multiplier)
	if (CurrentDebtStage == EAshenIntegrationDebtStage::RuntimeNoise || CurrentDebtStage == EAshenIntegrationDebtStage::ForcedCollapse)
	{
		return 0.85f;
	}
	return 1.0f;
}
