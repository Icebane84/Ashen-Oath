// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenStanceCameraTraumaAdapter.h"

UAshenStanceCameraTraumaAdapter::UAshenStanceCameraTraumaAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenStanceCameraTraumaAdapter::EvaluateStanceCameraShake(
	EOathbringerMartialStance Stance,
	float& OutTraumaKick,
	float& OutFoVPunchDegrees) const
{
	switch (Stance)
	{
	case EOathbringerMartialStance::VomTag_HighWrath:
		OutTraumaKick = 0.45f; // Heavy downward screen kick
		OutFoVPunchDegrees = 4.0f;
		break;

	case EOathbringerMartialStance::Mordhau_HalfSword:
		OutTraumaKick = 0.35f; // Sharp blunt screen shudder
		OutFoVPunchDegrees = 2.5f;
		break;

	case EOathbringerMartialStance::Ochs_CrownGuard:
		OutTraumaKick = 0.20f; // Quick deflecting shudder
		OutFoVPunchDegrees = 1.5f;
		break;

	case EOathbringerMartialStance::Pflug_LowPlow:
	default:
		OutTraumaKick = 0.15f; // Rapid forward punch
		OutFoVPunchDegrees = 3.0f;
		break;
	}
}
