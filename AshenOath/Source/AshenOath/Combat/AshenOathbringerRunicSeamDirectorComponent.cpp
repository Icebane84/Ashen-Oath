// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenOathbringerRunicSeamDirectorComponent.h"

UAshenOathbringerRunicSeamDirectorComponent::UAshenOathbringerRunicSeamDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FLinearColor UAshenOathbringerRunicSeamDirectorComponent::GetSeamColorForStance(
	EOathbringerMartialStance Stance) const
{
	switch (Stance)
	{
	case EOathbringerMartialStance::VomTag_HighWrath:
		return FLinearColor(1.0f, 0.15f, 0.05f, 1.0f); // Crimson Embers
	case EOathbringerMartialStance::Pflug_LowPlow:
		return FLinearColor(0.9f, 0.95f, 1.0f, 1.0f); // White Flame
	case EOathbringerMartialStance::Ochs_CrownGuard:
		return FLinearColor(1.0f, 0.85f, 0.2f, 1.0f); // Gold Shimmer
	case EOathbringerMartialStance::Mordhau_HalfSword:
	default:
		return FLinearColor(0.35f, 0.1f, 0.6f, 1.0f); // Umbral Shock
	}
}

float UAshenOathbringerRunicSeamDirectorComponent::GetEmissiveIntensityForStance(
	EOathbringerMartialStance Stance) const
{
	switch (Stance)
	{
	case EOathbringerMartialStance::VomTag_HighWrath:
		return 4.50f;
	case EOathbringerMartialStance::Ochs_CrownGuard:
		return 4.00f;
	case EOathbringerMartialStance::Pflug_LowPlow:
		return 3.80f;
	case EOathbringerMartialStance::Mordhau_HalfSword:
	default:
		return 3.20f;
	}
}
