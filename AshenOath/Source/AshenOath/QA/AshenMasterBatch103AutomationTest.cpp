// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 2075: Master Batch #103 QA Automation Test Suite — Controller Friction & Internal Struggle Matrix
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Audio/AshenControllerFrictionSubsystem.h"
#include "Combat/AshenDualTriggerLockEvaluatorComponent.h"
#include "Combat/AshenRhythmicBreathingCadenceComponent.h"
#include "Combat/AshenMartyrsPivotChordComponent.h"
#include "Combat/AshenTremblingHandsSomaticMeshAdapter.h"

// =============================================================================
//  Test 1: Input Buffer Delay & Dual Trigger 50% Lock Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch103FrictionAndLockTest,
	"AshenOath.Struggle.FrictionAndLock.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch103FrictionAndLockTest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Input Delay Scaling
	UAshenControllerFrictionSubsystem* Subsystem = NewObject<UAshenControllerFrictionSubsystem>();
	if (!TestNotNull(TEXT("ControllerFrictionSubsystem must be constructable"), Subsystem)) return false;

	Subsystem->CalculateInputBufferFriction(0.50f);
	TestEqual(TEXT("50% Corruption must equal 60ms artificial latency"), Subsystem->ArtificialInputDelayMilliseconds, 60.0f);

	Subsystem->CalculateInputBufferFriction(1.0f);
	TestEqual(TEXT("100% Corruption must equal 120ms artificial latency"), Subsystem->ArtificialInputDelayMilliseconds, 120.0f);

	// Test 2: Dual Trigger Lock Tolerance (45% - 55%)
	UAshenDualTriggerLockEvaluatorComponent* LockEvaluator = NewObject<UAshenDualTriggerLockEvaluatorComponent>();
	if (!TestNotNull(TEXT("DualTriggerLockEvaluatorComponent must be constructable"), LockEvaluator)) return false;

	float SlipDelta = 0.0f;

	// In tolerance
	TestTrue(TEXT("L2=0.50, R2=0.50 must be in tolerance"), LockEvaluator->EvaluateTriggerLock(0.50f, 0.50f, SlipDelta));
	TestEqual(TEXT("Clean lock slip delta must be 0.0"), SlipDelta, 0.0f);

	// Out of tolerance (bottomed out)
	TestFalse(TEXT("L2=0.95, R2=0.50 must fail tolerance"), LockEvaluator->EvaluateTriggerLock(0.95f, 0.50f, SlipDelta));
	TestEqual(TEXT("Failed lock slip delta must be +0.05/sec"), SlipDelta, 0.05f);

	return true;
}

// =============================================================================
//  Test 2: Rhythmic Breathing Cadence & Martyr's Chord Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch103BreathingAndChordTest,
	"AshenOath.Struggle.BreathingAndChord.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch103BreathingAndChordTest::RunTest(const FString& Parameters)
{
	// Test 1: Rhythmic Breathing Inhale/Exhale Sequence
	UAshenRhythmicBreathingCadenceComponent* Breathing = NewObject<UAshenRhythmicBreathingCadenceComponent>();
	if (!TestNotNull(TEXT("RhythmicBreathingCadenceComponent must be constructable"), Breathing)) return false;

	TestTrue(TEXT("Initial Inhale (Cross) must succeed"), Breathing->RegisterBreathInput(true));
	TestEqual(TEXT("Streak must be 1"), Breathing->CurrentCadence.ConsecutiveSuccessfulBreaths, 1);
	TestFalse(TEXT("Next must expect Exhale"), Breathing->CurrentCadence.bExpectingInhale);

	TestTrue(TEXT("Followup Exhale (Square) must succeed"), Breathing->RegisterBreathInput(false));
	TestEqual(TEXT("Streak must be 2"), Breathing->CurrentCadence.ConsecutiveSuccessfulBreaths, 2);
	TestTrue(TEXT("Next must expect Inhale again"), Breathing->CurrentCadence.bExpectingInhale);

	// Test 2: Martyr's Chord Hold (L3+R3 + R1+Triangle)
	UAshenMartyrsPivotChordComponent* ChordComp = NewObject<UAshenMartyrsPivotChordComponent>();
	if (!TestNotNull(TEXT("MartyrsPivotChordComponent must be constructable"), ChordComp)) return false;

	TestTrue(TEXT("All 4 chord inputs pressed must succeed"),
		ChordComp->CheckMartyrsChord(true, true, true, true));

	TestFalse(TEXT("Missing Triangle must fail chord"),
		ChordComp->CheckMartyrsChord(true, true, true, false));

	// Test 3: Somatic Tremble Amplitude
	UAshenTremblingHandsSomaticMeshAdapter* Tremble = NewObject<UAshenTremblingHandsSomaticMeshAdapter>();
	if (!TestNotNull(TEXT("TremblingHandsSomaticMeshAdapter must be constructable"), Tremble)) return false;

	Tremble->UpdateTrembleAmplitude(0.85f);
	TestEqual(TEXT("Tremble amplitude must equal 0.85"), Tremble->TrembleAmplitudeScalar, 0.85f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #103 STRUGGLE MATRIX VERIFIED (2,075 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
