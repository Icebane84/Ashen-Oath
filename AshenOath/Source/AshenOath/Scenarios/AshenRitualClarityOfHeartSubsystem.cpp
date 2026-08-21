// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenRitualClarityOfHeartSubsystem.h"

UAshenRitualClarityOfHeartSubsystem::UAshenRitualClarityOfHeartSubsystem()
{
}

bool UAshenRitualClarityOfHeartSubsystem::AdvanceRitual(float DeltaProgress)
{
	RitualContext.RitualProgressPercent = FMath::Clamp(RitualContext.RitualProgressPercent + DeltaProgress, 0.0f, 1.0f);
	return (RitualContext.RitualProgressPercent >= 1.0f);
}

float UAshenRitualClarityOfHeartSubsystem::EvaluateDebtSpikeOnInterruption(float ProgressAtInterrupt) const
{
	// Breaking the ritual near climax incurs a devastating psychic debt spike (up to 45% debt)
	return FMath::Clamp(0.15f + (ProgressAtInterrupt * 0.30f), 0.15f, 0.45f);
}
