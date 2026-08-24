// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenQuartzMusicConductorSubsystem.h"

UAshenQuartzMusicConductorSubsystem::UAshenQuartzMusicConductorSubsystem()
{
	MatrixState.Stem01_Vol = 0.10f;
	MatrixState.Stem02_Vol = 0.00f;
	MatrixState.Stem03_Vol = 0.80f;
	MatrixState.Stem04_Vol = 0.00f;
	MatrixState.Stem05_Vol = 1.00f;
	MatrixState.Stem06_Vol = 0.20f;
	MatrixState.MasterBPM = 115.0f;
	MatrixState.FlowState = ECombatFlowState::StandardTrioBaseline;
	MatrixState.ActiveFilter = EAlchemicalAudioFilter::None;
	FlowDurationRemainingSeconds = 0.0f;
}

void UAshenQuartzMusicConductorSubsystem::UpdateCombatStemMatrix(float Corruption01, float Burnout01)
{
	if (MatrixState.FlowState == ECombatFlowState::SymbioticResonance)
	{
		return; // Handled by Flow State
	}

	const float C = FMath::Clamp(Corruption01, 0.0f, 1.0f);
	const float B = FMath::Clamp(Burnout01, 0.0f, 1.0f);

	MatrixState.Stem01_Vol = FMath::Clamp(0.10f + (0.90f * C), 0.10f, 1.0f);
	MatrixState.Stem02_Vol = (C >= 0.25f) ? FMath::Clamp((C - 0.25f) / 0.75f, 0.0f, 1.0f) : 0.0f;
	MatrixState.Stem03_Vol = FMath::Clamp(0.80f - (0.50f * B), 0.30f, 0.80f);
	MatrixState.Stem04_Vol = FMath::Clamp(C * 0.70f, 0.0f, 0.70f);
	MatrixState.Stem05_Vol = FMath::Clamp(1.00f - (0.70f * C), 0.30f, 1.00f);
	MatrixState.Stem06_Vol = FMath::Clamp(0.20f + (0.60f * (1.0f - C)), 0.20f, 0.80f);

	if (C >= 0.70f || B >= 0.70f)
	{
		MatrixState.FlowState = ECombatFlowState::CrisisNearBreakdown;
	}
	else if (C >= 0.30f || B >= 0.30f)
	{
		MatrixState.FlowState = ECombatFlowState::SicknessDeepening;
	}
	else
	{
		MatrixState.FlowState = ECombatFlowState::StandardTrioBaseline;
	}

	OnStemMatrixUpdated.Broadcast(MatrixState);
	OnFlowStateChanged.Broadcast(MatrixState.FlowState, FlowDurationRemainingSeconds);
}

void UAshenQuartzMusicConductorSubsystem::TriggerSymbioticResonance(float DurationSeconds)
{
	MatrixState.FlowState = ECombatFlowState::SymbioticResonance;
	FlowDurationRemainingSeconds = DurationSeconds;

	// Symbiotic Resonance Stem Convergence
	MatrixState.Stem01_Vol = 0.05f; // Industrial muted
	MatrixState.Stem02_Vol = 0.00f; // Parasite silenced completely
	MatrixState.Stem03_Vol = 1.00f; // Triumphant violin ostinato
	MatrixState.Stem04_Vol = 1.00f; // Clean open guitar chords
	MatrixState.Stem05_Vol = 0.00f; // Choir swapped for human vocals
	MatrixState.Stem06_Vol = 1.00f; // Driving Afro-pop groove

	OnStemMatrixUpdated.Broadcast(MatrixState);
	OnFlowStateChanged.Broadcast(MatrixState.FlowState, FlowDurationRemainingSeconds);
}

void UAshenQuartzMusicConductorSubsystem::ApplyAlchemicalFilter(EAlchemicalAudioFilter Filter, float DurationSeconds)
{
	MatrixState.ActiveFilter = Filter;
	OnAlchemicalFilterEngaged.Broadcast(Filter, DurationSeconds);
}

void UAshenQuartzMusicConductorSubsystem::DispatchBarDownbeat(int32 BarIndex)
{
	OnQuartzBarDownbeat.Broadcast(BarIndex);
}
