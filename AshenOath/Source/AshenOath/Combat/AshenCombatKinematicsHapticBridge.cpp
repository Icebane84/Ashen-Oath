// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenCombatKinematicsHapticBridge.h"

UAshenCombatKinematicsHapticBridge::UAshenCombatKinematicsHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCombatKinematicsHapticBridge::EvaluateKinematicsHaptics(
	bool bInCardiacExhaustion,
	EPoiseStaggerState StaggerState,
	EParryRiposteQuality ParryQuality,
	float& OutTriggerResistance,
	float& OutStaggerMotorImpulse,
	float& OutDeflectionClickGain)
{
	// 1. Adaptive Trigger Resistance (heavy when exhausted)
	OutTriggerResistance = bInCardiacExhaustion ? 0.85f : 0.10f;

	// 2. Stagger Motor Impulse (0.95 heavy low-frequency motor kick on guard break)
	if (StaggerState == EPoiseStaggerState::PoiseBroken)
	{
		OutStaggerMotorImpulse = 0.95f;
	}
	else if (StaggerState == EPoiseStaggerState::UnsteadyGuard)
	{
		OutStaggerMotorImpulse = 0.40f;
	}
	else
	{
		OutStaggerMotorImpulse = 0.0f;
	}

	// 3. Crisp Deflection Click (0.80 sharp 220Hz pulse on perfect riposte)
	if (ParryQuality == EParryRiposteQuality::PerfectRiposte)
	{
		OutDeflectionClickGain = 0.80f;
	}
	else if (ParryQuality == EParryRiposteQuality::StandardParry)
	{
		OutDeflectionClickGain = 0.50f;
	}
	else
	{
		OutDeflectionClickGain = 0.0f;
	}
}
