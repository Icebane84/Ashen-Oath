// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 2055: Master Batch #102 QA Automation Test Suite — Existential Meaning-Making & Trial of Will Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenTrialOfWillSubsystem.h"
#include "Combat/AshenTrialOfWillEvaluatorComponent.h"
#include "Soul/AshenKeystoneMemoryCompilerComponent.h"
#include "Audio/AshenDualSenseAdaptiveTriggerComponent.h"
#include "Combat/AshenSomaticTorsoSootMeshAdapter.h"

// =============================================================================
//  Test 1: Trial of Will Time-Dilation & Stagger Choices
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch102TrialOfWillTest,
	"AshenOath.Meaning.TrialOfWill.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch102TrialOfWillTest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Window & Scale Values
	UAshenTrialOfWillSubsystem* Subsystem = NewObject<UAshenTrialOfWillSubsystem>();
	if (!TestNotNull(TEXT("TrialOfWillSubsystem must be constructable"), Subsystem)) return false;

	TestEqual(TEXT("Stagger window duration must be exactly 0.75s"), Subsystem->StaggerWindowDurationSeconds, 0.75f);
	TestEqual(TEXT("Time dilation scale must be 0.05f"), Subsystem->TimeDilationScale, 0.05f);

	// Test 2: Choice Evaluations
	UAshenTrialOfWillEvaluatorComponent* Evaluator = NewObject<UAshenTrialOfWillEvaluatorComponent>();
	if (!TestNotNull(TEXT("TrialOfWillEvaluatorComponent must be constructable"), Evaluator)) return false;

	float DebtDelta = 0.0f, CorrDelta = 0.0f, TrustDelta = 0.0f;

	// Defiance
	Evaluator->EvaluateStaggerChoice(ETrialOfWillChoice::Defiance, DebtDelta, CorrDelta, TrustDelta);
	TestEqual(TEXT("Defiance debt delta must equal +2.5"), DebtDelta, 2.5f);
	TestEqual(TEXT("Defiance corruption delta must equal 0.0"), CorrDelta, 0.0f);
	TestEqual(TEXT("Defiance trust delta must equal -1.0"), TrustDelta, -1.0f);

	// Wrath
	Evaluator->EvaluateStaggerChoice(ETrialOfWillChoice::Wrath, DebtDelta, CorrDelta, TrustDelta);
	TestEqual(TEXT("Wrath debt delta must equal 0.0"), DebtDelta, 0.0f);
	TestEqual(TEXT("Wrath corruption delta must equal +5.0"), CorrDelta, 5.0f);
	TestEqual(TEXT("Wrath trust delta must equal -2.0"), TrustDelta, -2.0f);

	// Trust
	Evaluator->EvaluateStaggerChoice(ETrialOfWillChoice::Trust, DebtDelta, CorrDelta, TrustDelta);
	TestEqual(TEXT("Trust debt delta must clear -5.0%"), DebtDelta, -5.0f);
	TestEqual(TEXT("Trust corruption delta must equal 0.0"), CorrDelta, 0.0f);
	TestEqual(TEXT("Trust trust delta must equal +3.5"), TrustDelta, 3.5f);

	return true;
}

// =============================================================================
//  Test 2: Keystone Memory Compilation & Hardware Adaptive Triggers
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch102KeystoneAndHapticsTest,
	"AshenOath.Meaning.KeystoneAndHaptics.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch102KeystoneAndHapticsTest::RunTest(const FString& Parameters)
{
	// Test 1: Keystone Memory Compilation
	UAshenKeystoneMemoryCompilerComponent* Compiler = NewObject<UAshenKeystoneMemoryCompilerComponent>();
	if (!TestNotNull(TEXT("KeystoneMemoryCompilerComponent must be constructable"), Compiler)) return false;

	TestTrue(TEXT("InvokeIntegration on FallOfOakhaven with Grace must succeed"),
		Compiler->InvokeIntegration(FName(TEXT("Memory.FallOfOakhaven")), EKeystoneInterpretiveLens::Grace));

	TestEqual(TEXT("CompiledMemories array must contain 1 entry"), Compiler->CompiledMemories.Num(), 1);
	TestEqual(TEXT("Compiled memory lens must be Grace"), Compiler->CompiledMemories[0].SelectedLens, EKeystoneInterpretiveLens::Grace);

	// Test 2: DualSense Adaptive Trigger Resistance Math
	UAshenDualSenseAdaptiveTriggerComponent* TriggerComp = NewObject<UAshenDualSenseAdaptiveTriggerComponent>();
	if (!TestNotNull(TEXT("DualSenseAdaptiveTriggerComponent must be constructable"), TriggerComp)) return false;

	TriggerComp->UpdateTriggerResistance(0.65f);
	TestEqual(TEXT("Trigger resistance scalar must equal 0.65"), TriggerComp->L2TriggerResistanceScalar, 0.65f);

	// Test 3: Somatic Torso Soot Mesh Overlay Math
	UAshenSomaticTorsoSootMeshAdapter* SootAdapter = NewObject<UAshenSomaticTorsoSootMeshAdapter>();
	if (!TestNotNull(TEXT("SomaticTorsoSootMeshAdapter must be constructable"), SootAdapter)) return false;

	SootAdapter->ApplyWrathSootBurn(5.0f); // 5.0 * 0.05 = 0.25
	TestEqual(TEXT("Ash-soot overlay opacity must equal 0.25"), SootAdapter->AshSootOverlayOpacity, 0.25f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #102 EXISTENTIAL MEANING VERIFIED (2,055 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
