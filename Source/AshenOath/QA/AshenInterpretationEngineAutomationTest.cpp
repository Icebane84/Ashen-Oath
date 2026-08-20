// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 620: Ashen Interpretation Engine Automation Tests (UMB-INT-001)

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenInterpretationEngineSubsystem.h"
#include "AshenIntegrativeMemoryPassComponent.h"
#include "AshenHermeneuticFragmentationComponent.h"
#include "AshenInterpretiveClaritySubsystem.h"
#include "AshenMilestone620SynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Interpretation Engine Subsystem — Dual Pass Execution
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenInterpretationEngineSubsystemTest,
	"AshenOath.InterpretationEngine.Subsystem.PassExecution",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenInterpretationEngineSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenInterpretationEngineSubsystem* EngineSys = NewObject<UAshenInterpretationEngineSubsystem>();
	if (!TestNotNull(TEXT("InterpretationEngineSubsystem must be constructable"), EngineSys)) return false;

	const FName MemoryID(TEXT("Memory.MalakorConfrontation"));
	EngineSys->ExecuteInterpretationPass(MemoryID, EInterpretationPassType::Integrative);
	TestEqual(TEXT("TotalPassesExecuted must equal 1"), EngineSys->TotalPassesExecuted, 1);

	return true;
}

// =============================================================================
//  Test 2: Integrative Memory Pass Component — Memory Stabilization
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenIntegrativeMemoryPassComponentTest,
	"AshenOath.IntegrativePass.Component.Stabilize",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenIntegrativeMemoryPassComponentTest::RunTest(const FString& Parameters)
{
	UAshenIntegrativeMemoryPassComponent* PassComp = NewObject<UAshenIntegrativeMemoryPassComponent>();
	if (!TestNotNull(TEXT("IntegrativeMemoryPassComponent must be constructable"), PassComp)) return false;

	PassComp->ExecuteIntegrativePass(FName(TEXT("Memory.SunderingOath")), FName(TEXT("Lens.Grace")));
	TestEqual(TEXT("TotalMemoriesIntegrated must equal 1"), PassComp->TotalMemoriesIntegrated, 1);

	return true;
}

// =============================================================================
//  Test 3: Hermeneutic Fragmentation Component — Uncertainty Erosion
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHermeneuticFragmentationComponentTest,
	"AshenOath.FragmentationPass.Component.Erosion",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenHermeneuticFragmentationComponentTest::RunTest(const FString& Parameters)
{
	UAshenHermeneuticFragmentationComponent* FragComp = NewObject<UAshenHermeneuticFragmentationComponent>();
	if (!TestNotNull(TEXT("HermeneuticFragmentationComponent must be constructable"), FragComp)) return false;

	FragComp->ExecuteFragmentationPass(FName(TEXT("Memory.BlackwoodBetrayal")), 20.0f);
	TestEqual(TEXT("TotalErosionAccumulated must equal 20.0"), FragComp->TotalErosionAccumulated, 20.0f);

	return true;
}

// =============================================================================
//  Test 4: Interpretive Clarity Subsystem — Whisper Resistance
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenInterpretiveClaritySubsystemTest,
	"AshenOath.Clarity.Subsystem.WhisperResistance",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenInterpretiveClaritySubsystemTest::RunTest(const FString& Parameters)
{
	UAshenInterpretiveClaritySubsystem* ClaritySys = NewObject<UAshenInterpretiveClaritySubsystem>();
	if (!TestNotNull(TEXT("InterpretiveClaritySubsystem must be constructable"), ClaritySys)) return false;

	TestTrue(TEXT("Clarity (0.85) must resist whisper intensity 50.0"), ClaritySys->EvaluateClarityAgainstWhisper(50.0f));

	return true;
}
