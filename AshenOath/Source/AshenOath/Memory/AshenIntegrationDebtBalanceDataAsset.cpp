// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Memory/AshenIntegrationDebtBalanceDataAsset.h"

FIntegrationDebtStageThresholds UAshenIntegrationDebtBalanceDataAsset::GetClampedThresholds() const
{
	FIntegrationDebtStageThresholds Clamped = StageThresholds;
	Clamped.MemoryBleedThreshold = FMath::Clamp(Clamped.MemoryBleedThreshold, 0.10f, 0.70f);
	Clamped.RuntimeNoiseThreshold = FMath::Clamp(Clamped.RuntimeNoiseThreshold, 0.50f, 0.95f);
	Clamped.ForcedCollapseThreshold = FMath::Clamp(Clamped.ForcedCollapseThreshold, 0.80f, 1.00f);
	return Clamped;
}

FIntegrationDebtPenalties UAshenIntegrationDebtBalanceDataAsset::GetClampedPenalties() const
{
	FIntegrationDebtPenalties Clamped = Penalties;
	Clamped.DefaultParryWindowSeconds = FMath::Clamp(Clamped.DefaultParryWindowSeconds, 0.05f, 0.30f);
	Clamped.DegradedParryWindowSeconds = FMath::Clamp(Clamped.DegradedParryWindowSeconds, 0.02f, 0.20f);
	Clamped.StaminaRecoveryHandicap = FMath::Clamp(Clamped.StaminaRecoveryHandicap, 0.05f, 0.60f);
	Clamped.MemoryBleedDesaturation = FMath::Clamp(Clamped.MemoryBleedDesaturation, 0.0f, 1.0f);
	Clamped.RuntimeNoiseDesaturation = FMath::Clamp(Clamped.RuntimeNoiseDesaturation, 0.0f, 1.0f);
	return Clamped;
}
