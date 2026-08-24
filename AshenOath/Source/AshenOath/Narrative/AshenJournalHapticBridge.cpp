// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Narrative/AshenJournalHapticBridge.h"

UAshenJournalHapticBridge::UAshenJournalHapticBridge()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenJournalHapticBridge::EvaluateJournalHaptics(
	bool bPageTurned,
	bool bWritingMarginalia,
	ECampfireReflectionMood Mood,
	float& OutTriggerPageSnapResistance,
	float& OutQuillVibration400Hz,
	float& OutEmberCrackleRumble)
{
	// Page-snap trigger resistance pulse
	OutTriggerPageSnapResistance = bPageTurned ? 0.70f : 0.05f;

	// Quill writing micro-haptic vibration (400Hz)
	OutQuillVibration400Hz = bWritingMarginalia ? 0.45f : 0.0f;

	// Ambient campfire rumble
	switch (Mood)
	{
	case ECampfireReflectionMood::SomberSilence:
		OutEmberCrackleRumble = 0.15f;
		break;
	case ECampfireReflectionMood::SharedCatharsis:
		OutEmberCrackleRumble = 0.60f;
		break;
	case ECampfireReflectionMood::TemperedResolve:
	default:
		OutEmberCrackleRumble = 0.35f;
		break;
	}
}
