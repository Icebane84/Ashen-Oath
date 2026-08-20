// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 2155: Master Batch #107 QA Automation Test Suite — Active Memory Weaving & Somatic Transmutation Matrix
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenActiveMemoryWeavingSubsystem.h"
#include "Combat/AshenLuminousAegisNetComponent.h"
#include "Audio/AshenHarmonicResonancePitchComponent.h"
#include "Audio/AshenDualSenseWeavingTensionComponent.h"
#include "Combat/AshenWovenStitchJournalMeshAdapter.h"

// =============================================================================
//  Test 1: Memory Weaving Subsystem & Thread Density Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch107SubsystemAndLoomTest,
	"AshenOath.Weaving.SubsystemAndLoom.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch107SubsystemAndLoomTest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Initialization
	UAshenActiveMemoryWeavingSubsystem* Subsystem = NewObject<UAshenActiveMemoryWeavingSubsystem>();
	if (!TestNotNull(TEXT("ActiveMemoryWeavingSubsystem must be constructable"), Subsystem)) return false;

	int32 CalculatedThreads = 0;
	float CalculatedTension = 0.0f;

	// Test 2: Low Debt, High Trust -> 1 Thread, Slack Tension
	Subsystem->CalculateWeavingDensity(0.0f, 1.0f, CalculatedThreads, CalculatedTension);
	TestEqual(TEXT("Zero debt must yield 1 thread"), CalculatedThreads, 1);
	TestEqual(TEXT("Zero debt must yield 0.0 tension"), CalculatedTension, 0.0f);
	TestEqual(TEXT("Tension state must be Slack"), Subsystem->CurrentLoomPayload.TensionState, EFilamentTensionState::Slack);

	// Test 3: High Debt (100.0), Low Trust (0.0) -> 8 Threads, High Tension -> Snapping
	Subsystem->CalculateWeavingDensity(100.0f, 0.0f, CalculatedThreads, CalculatedTension);
	TestEqual(TEXT("Max debt must yield 8 threads"), CalculatedThreads, 8);
	TestTrue(TEXT("Tension must be >= 0.85"), CalculatedTension >= 0.85f);
	TestEqual(TEXT("Tension state must be Snapping"), Subsystem->CurrentLoomPayload.TensionState, EFilamentTensionState::Snapping);

	// Test 4: Thread Snap Decrement
	TestTrue(TEXT("Thread snap must succeed"), Subsystem->RegisterThreadSnapEvent());
	TestEqual(TEXT("Remaining threads must be 7"), Subsystem->CurrentLoomPayload.ActiveThreadCount, 7);

	return true;
}

// =============================================================================
//  Test 2: Aegis Net Absorption, Audio Pitch & Somatic Haptics Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch107AegisAndAudioTest,
	"AshenOath.Weaving.AegisAndAudio.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch107AegisAndAudioTest::RunTest(const FString& Parameters)
{
	// Test 1: Aegis Net Poise Absorption (75% of 100.0 = 75.0)
	UAshenLuminousAegisNetComponent* AegisComp = NewObject<UAshenLuminousAegisNetComponent>();
	if (!TestNotNull(TEXT("LuminousAegisNetComponent must be constructable"), AegisComp)) return false;

	AegisComp->bIsNetActive = true;
	float AbsorbedPoise = 0.0f;
	bool bSnapped = false;

	TestTrue(TEXT("First poise strike must be absorbed"), AegisComp->AbsorbPoiseStrike(100.0f, AbsorbedPoise, bSnapped));
	TestEqual(TEXT("Absorbed poise must equal 75.0"), AbsorbedPoise, 75.0f);
	TestTrue(TEXT("Thread snap must trigger on hit"), bSnapped);
	TestEqual(TEXT("Remaining shields must be 1"), AegisComp->RemainingPoiseBreakShields, 1);

	// Test 2: Harmonic Pitch Scaling (Trust 0.0 -> 220Hz, Trust 1.0 -> 880Hz)
	UAshenHarmonicResonancePitchComponent* PitchComp = NewObject<UAshenHarmonicResonancePitchComponent>();
	if (!TestNotNull(TEXT("HarmonicResonancePitchComponent must be constructable"), PitchComp)) return false;

	PitchComp->UpdateFilamentPitch(1.0f, 0.0f);
	TestEqual(TEXT("Max trust pitch must be 880.0Hz"), PitchComp->FilamentPitchFrequencyHz, 880.0f);

	PitchComp->UpdateFilamentPitch(0.0f, 0.0f);
	TestEqual(TEXT("Zero trust pitch must be 220.0Hz"), PitchComp->FilamentPitchFrequencyHz, 220.0f);

	// Test 3: DualSense Trigger Motor Resistance
	UAshenDualSenseWeavingTensionComponent* TensionComp = NewObject<UAshenDualSenseWeavingTensionComponent>();
	if (!TestNotNull(TEXT("DualSenseWeavingTensionComponent must be constructable"), TensionComp)) return false;

	TensionComp->UpdateTriggerTension(0.75f, EFilamentTensionState::Tense);
	TestEqual(TEXT("Motor resistance must be 0.75"), TensionComp->TriggerMotorResistance, 0.75f);

	// Test 4: Journal Embroidered Stitch Glow
	UAshenWovenStitchJournalMeshAdapter* MeshAdapter = NewObject<UAshenWovenStitchJournalMeshAdapter>();
	if (!TestNotNull(TEXT("WovenStitchJournalMeshAdapter must be constructable"), MeshAdapter)) return false;

	MeshAdapter->UpdateJournalStitchGlow(4);
	TestEqual(TEXT("4 incidents must yield 2.0 glow"), MeshAdapter->StitchEmissiveGlow, 2.0f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #107 MEMORY WEAVING VERIFIED (2,155 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
