// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 825: Ashen DualSense Haptic Friction & Temporal Dilation Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDualSenseAdaptiveTriggerHapticFrictionComponent.h"
#include "AshenSubliminalPeripheralThoughtOverlayComponent.h"
#include "AshenParasiteGutturalHeartbeatAudioModulator.h"

// =============================================================================
//  Test 1: DualSense Adaptive Trigger Haptic Friction Component — Threshold
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDualSenseAdaptiveTriggerHapticFrictionComponentTest,
	"AshenOath.AdaptiveTriggers.Component.Threshold",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDualSenseAdaptiveTriggerHapticFrictionComponentTest::RunTest(const FString& Parameters)
{
	UAshenDualSenseAdaptiveTriggerHapticFrictionComponent* TriggerComp = NewObject<UAshenDualSenseAdaptiveTriggerHapticFrictionComponent>();
	if (!TestNotNull(TEXT("DualSenseAdaptiveTriggerHapticFrictionComponent must be constructable"), TriggerComp)) return false;

	TestTrue(TEXT("Force 0.90 must break threshold 0.85"), TriggerComp->EvaluateTriggerPressPastThreshold(0.90f));

	return true;
}

// =============================================================================
//  Test 2: Subliminal Peripheral Thought Overlay Component — Flicker
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSubliminalPeripheralThoughtOverlayComponentTest,
	"AshenOath.SubliminalThought.Component.Flicker",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSubliminalPeripheralThoughtOverlayComponentTest::RunTest(const FString& Parameters)
{
	UAshenSubliminalPeripheralThoughtOverlayComponent* ThoughtComp = NewObject<UAshenSubliminalPeripheralThoughtOverlayComponent>();
	if (!TestNotNull(TEXT("SubliminalPeripheralThoughtOverlayComponent must be constructable"), ThoughtComp)) return false;

	ThoughtComp->FlickerSubliminalThought(FText::FromString(TEXT("Let go")));
	TestEqual(TEXT("TotalThoughtsFlickered must equal 1"), ThoughtComp->TotalThoughtsFlickered, 1);

	return true;
}

// =============================================================================
//  Test 3: Parasite Guttural Heartbeat Audio Modulator — Update Pressure
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenParasiteGutturalHeartbeatAudioModulatorTest,
	"AshenOath.HeartbeatAudio.Subsystem.UpdatePressure",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenParasiteGutturalHeartbeatAudioModulatorTest::RunTest(const FString& Parameters)
{
	UAshenParasiteGutturalHeartbeatAudioModulator* AudioMod = NewObject<UAshenParasiteGutturalHeartbeatAudioModulator>();
	if (!TestNotNull(TEXT("ParasiteGutturalHeartbeatAudioModulator must be constructable"), AudioMod)) return false;

	AudioMod->UpdateHeartbeatAudioPressure(0.20f);
	TestEqual(TEXT("TotalAudioPulsesPlayed must equal 1"), AudioMod->TotalAudioPulsesPlayed, 1);

	return true;
}
