// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenStanceKinematicsEvaluator.h"

UAshenStanceKinematicsEvaluator::UAshenStanceKinematicsEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

float UAshenStanceKinematicsEvaluator::EvaluateDamageMultiplier(
	EOathbringerMartialStance Stance) const
{
	switch (Stance)
	{
	case EOathbringerMartialStance::VomTag_HighWrath:
		return 1.40f;
	case EOathbringerMartialStance::Mordhau_HalfSword:
		return 1.25f;
	case EOathbringerMartialStance::Ochs_CrownGuard:
		return 1.10f;
	case EOathbringerMartialStance::Pflug_LowPlow:
	default:
		return 1.00f;
	}
}

float UAshenStanceKinematicsEvaluator::EvaluatePoiseDamageMultiplier(
	EOathbringerMartialStance Stance) const
{
	switch (Stance)
	{
	case EOathbringerMartialStance::Mordhau_HalfSword:
		return 1.75f; // +75% poise damage on armor & shields
	case EOathbringerMartialStance::VomTag_HighWrath:
		return 1.40f;
	case EOathbringerMartialStance::Ochs_CrownGuard:
		return 1.15f;
	case EOathbringerMartialStance::Pflug_LowPlow:
	default:
		return 0.90f;
	}
}

float UAshenStanceKinematicsEvaluator::EvaluateParryWindowSeconds(
	EOathbringerMartialStance Stance) const
{
	switch (Stance)
	{
	case EOathbringerMartialStance::Ochs_CrownGuard:
		return 0.22f; // +0.12s leniency
	case EOathbringerMartialStance::Pflug_LowPlow:
	case EOathbringerMartialStance::Mordhau_HalfSword:
		return 0.10f;
	case EOathbringerMartialStance::VomTag_HighWrath:
	default:
		return 0.08f;
	}
}

float UAshenStanceKinematicsEvaluator::EvaluateArmorPenetration(
	EOathbringerMartialStance Stance) const
{
	switch (Stance)
	{
	case EOathbringerMartialStance::Mordhau_HalfSword:
		return 1.00f; // 100% Armor Penetration
	case EOathbringerMartialStance::Pflug_LowPlow:
		return 0.35f;
	case EOathbringerMartialStance::VomTag_HighWrath:
		return 0.20f;
	case EOathbringerMartialStance::Ochs_CrownGuard:
	default:
		return 0.15f;
	}
}
