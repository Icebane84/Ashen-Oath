// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenScenario10MissionSubsystem.h"

UAshenScenario10MissionSubsystem::UAshenScenario10MissionSubsystem()
{
	ConvergenceState.ApotheosisResonance01 = 0.0f;
	ConvergenceState.CombinedTrustScore01 = 0.85f;
	ConvergenceState.IntegrationDebt01 = 0.20f;
	ConvergenceState.DamageMultiplier = 1.0f;
	ConvergenceState.ResonanceStage = EApotheosisResonanceStage::DormantLatent;
	ConvergenceState.ResolvedEnding = EZenithConsequenceEnding::RadiantTransfiguration;
	ConvergenceState.bConsequenceResolved = false;
}

void UAshenScenario10MissionSubsystem::SetApotheosisResonance(float Resonance01)
{
	ConvergenceState.ApotheosisResonance01 = FMath::Clamp(Resonance01, 0.0f, 1.0f);

	if (ConvergenceState.ApotheosisResonance01 >= 1.0f)
	{
		ConvergenceState.ResonanceStage = EApotheosisResonanceStage::SovereignApotheosis;
		ConvergenceState.DamageMultiplier = 4.0f;
	}
	else if (ConvergenceState.ApotheosisResonance01 >= 0.50f)
	{
		ConvergenceState.ResonanceStage = EApotheosisResonanceStage::HarmonicBuildup;
		ConvergenceState.DamageMultiplier = 2.0f;
	}
	else
	{
		ConvergenceState.ResonanceStage = EApotheosisResonanceStage::DormantLatent;
		ConvergenceState.DamageMultiplier = 1.0f;
	}

	OnApotheosisStageChanged.Broadcast(ConvergenceState.ResonanceStage, ConvergenceState.ApotheosisResonance01);
}

EZenithConsequenceEnding UAshenScenario10MissionSubsystem::ResolveFinalConsequence(
	float TrustScore01,
	float Debt01,
	bool bBerserkDominant)
{
	ConvergenceState.CombinedTrustScore01 = FMath::Clamp(TrustScore01, 0.0f, 1.0f);
	ConvergenceState.IntegrationDebt01 = FMath::Clamp(Debt01, 0.0f, 1.0f);
	ConvergenceState.bConsequenceResolved = true;

	FText SummaryText;

	if (ConvergenceState.IntegrationDebt01 >= 0.85f)
	{
		ConvergenceState.ResolvedEnding = EZenithConsequenceEnding::AshenEclipse;
		SummaryText = FText::FromString(TEXT("The Void consumes the Sundered Spire. Kaelen ascents as an immortal world titan."));
	}
	else if (ConvergenceState.CombinedTrustScore01 < 0.40f)
	{
		ConvergenceState.ResolvedEnding = EZenithConsequenceEnding::BleedingFracture;
		SummaryText = FText::FromString(TEXT("The Oath is shattered. The companions part ways in bitter silence amid the ruins."));
	}
	else if (bBerserkDominant || ConvergenceState.CombinedTrustScore01 < 0.75f)
	{
		ConvergenceState.ResolvedEnding = EZenithConsequenceEnding::CauterizedHegemony;
		SummaryText = FText::FromString(TEXT("Through martial iron will, the Void is suppressed under absolute kinetic order."));
	}
	else
	{
		ConvergenceState.ResolvedEnding = EZenithConsequenceEnding::RadiantTransfiguration;
		SummaryText = FText::FromString(TEXT("Complete White Flame unification. The Sundered Realm is reborn into harmonic clarity."));
	}

	OnConsequenceEndingResolved.Broadcast(ConvergenceState.ResolvedEnding, SummaryText);
	return ConvergenceState.ResolvedEnding;
}
