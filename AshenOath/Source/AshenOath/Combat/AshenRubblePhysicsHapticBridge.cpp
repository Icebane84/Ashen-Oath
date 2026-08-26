// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenRubblePhysicsHapticBridge.h"

UAshenRubblePhysicsHapticBridge::UAshenRubblePhysicsHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenRubblePhysicsHapticBridge::EvaluateRubbleHaptics(
	EMasonryCollapseState CollapseState,
	EDemolitionToolType DemolitionTool,
	float RubbleMassKg,
	float& OutTriggerResistance,
	float& OutCollapseRumbleGain,
	float& OutDemolitionImpactPulse)
{
	// Trigger resistance based on rubble mass density
	const float MassRatio = FMath::Clamp(RubbleMassKg / 450.0f, 0.0f, 1.0f);
	OutTriggerResistance = 0.30f + (MassRatio * 0.65f); // 0.30 to 0.95

	// Collapse rumble gain
	OutCollapseRumbleGain = (CollapseState == EMasonryCollapseState::CollapsingImpact) ? 1.00f :
		(CollapseState == EMasonryCollapseState::TelegraphWarning ? 0.35f : 0.0f);

	// Demolition impact pulse
	OutDemolitionImpactPulse = (DemolitionTool != EDemolitionToolType::None) ? 0.85f : 0.0f;
}
