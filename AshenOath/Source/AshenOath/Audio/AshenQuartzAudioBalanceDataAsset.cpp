// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Audio/AshenQuartzAudioBalanceDataAsset.h"

FQuartzClockBalancing UAshenQuartzAudioBalanceDataAsset::GetClampedClockBalancing() const
{
	FQuartzClockBalancing Clamped = ClockBalancing;
	Clamped.BeatsPerMinute = FMath::Clamp(Clamped.BeatsPerMinute, 60.0f, 200.0f);
	Clamped.FlowStateDurationSeconds = FMath::Clamp(Clamped.FlowStateDurationSeconds, 2.0f, 16.0f);
	Clamped.FlowStaminaRegenMultiplier = FMath::Clamp(Clamped.FlowStaminaRegenMultiplier, 1.0f, 4.0f);
	return Clamped;
}

FAlchemicalFilterBalancing UAshenQuartzAudioBalanceDataAsset::GetClampedFilterBalancing() const
{
	FAlchemicalFilterBalancing Clamped = FilterBalancing;
	Clamped.SmokeLowPassCutoffHz = FMath::Clamp(Clamped.SmokeLowPassCutoffHz, 100.0f, 2000.0f);
	Clamped.TackleSideChainDuckingDB = FMath::Clamp(Clamped.TackleSideChainDuckingDB, -48.0f, 0.0f);
	Clamped.GloomwoodPitchOffsetSemitones = FMath::Clamp(Clamped.GloomwoodPitchOffsetSemitones, -24.0f, 0.0f);
	return Clamped;
}
