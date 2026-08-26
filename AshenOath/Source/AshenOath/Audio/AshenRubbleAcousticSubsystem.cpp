// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Audio/AshenRubbleAcousticSubsystem.h"

UAshenRubbleAcousticSubsystem::UAshenRubbleAcousticSubsystem()
{
}

float UAshenRubbleAcousticSubsystem::EvaluateStructuralGroanGain(float StructuralIntegrity01) const
{
	const float Strain = 1.0f - FMath::Clamp(StructuralIntegrity01, 0.0f, 1.0f);
	return FMath::Clamp(Strain * 0.90f, 0.0f, 0.90f);
}

float UAshenRubbleAcousticSubsystem::EvaluateFractureFrequencyHz(ERubbleFractureTier Tier) const
{
	switch (Tier)
	{
	case ERubbleFractureTier::FineGravel:
		return 4800.0f;
	case ERubbleFractureTier::MediumMasonry:
		return 2400.0f;
	case ERubbleFractureTier::HeavyBoulder:
		return 1200.0f;
	case ERubbleFractureTier::MonolithicArch:
	default:
		return 600.0f;
	}
}
