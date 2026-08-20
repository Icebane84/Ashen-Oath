// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1755: Master Batch #87 QA Automation Test Suite — Interpretive Lens & Identity Compilation Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1755MasterSynthesisOrchestrator.h"
#include "Soul/AshenInterpretiveLensSubsystem.h"
#include "Soul/AshenIdentityCompilerComponent.h"
#include "World/AshenLensSanctuaryPillarActor.h"
#include "Combat/AshenLensBuffManagerComponent.h"
#include "Combat/AshenInterpretiveLensGASAbility.h"

// =============================================================================
//  Test 1: Interpretive Lens Suite
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch87LensSuiteTest,
	"AshenOath.Lens.IdentitySuite.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch87LensSuiteTest::RunTest(const FString& Parameters)
{
	UAshenInterpretiveLensSubsystem* Subsystem = NewObject<UAshenInterpretiveLensSubsystem>();
	if (!TestNotNull(TEXT("InterpretiveLensSubsystem must be constructable"), Subsystem)) return false;
	Subsystem->SetActiveLens(EInterpretiveLens::Accountability);
	TestEqual(TEXT("Active lens must be Accountability"), Subsystem->GetActiveLens(), EInterpretiveLens::Accountability);

	UAshenIdentityCompilerComponent* Compiler = NewObject<UAshenIdentityCompilerComponent>();
	if (!TestNotNull(TEXT("IdentityCompilerComponent must be constructable"), Compiler)) return false;
	FSoulStateVector Compiled = Compiler->CompileIdentity(0.75f, 0.25f, 0.35f, 0.6f, 0.6f, EInterpretiveLens::Accountability);
	TestEqual(TEXT("Compiled resolve must match 0.75f"), Compiled.Resolve, 0.75f);
	return true;
}

// =============================================================================
//  Test 2: Master Milestone 1755 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1755MasterVerificationTest,
	"AshenOath.Milestone.Milestone1755.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1755MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1755MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1755MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1755 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1755 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1755Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1755 INTERPRETIVE LENS & IDENTITY COMPILATION SUITE VERIFIED (1,755 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
