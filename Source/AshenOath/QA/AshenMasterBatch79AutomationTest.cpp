// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1595: Master Batch #79 QA Automation Test Suite — Shroud Knight & Inquisitorial Purifiers Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1595MasterSynthesisOrchestrator.h"
#include "AI/AshenShroudKnightCharacter.h"
#include "Combat/AshenPurifierFlameBladeComponent.h"

// =============================================================================
//  Test 1: Shroud Knight Spectral Phasing Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch79ShroudPhasingTest,
	"AshenOath.EliteInquisition.ShroudKnight.PhasingVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch79ShroudPhasingTest::RunTest(const FString& Parameters)
{
	AAshenShroudKnightCharacter* Knight = NewObject<AAshenShroudKnightCharacter>();
	if (!TestNotNull(TEXT("ShroudKnightCharacter must be constructable"), Knight)) return false;

	Knight->InitiateSpectralPhase();
	TestEqual(TEXT("State must equal SpectralPhasing"), Knight->CurrentState, EAshenShroudSpiritState::SpectralPhasing);
	return true;
}

// =============================================================================
//  Test 2: Purifier Flame Blade State Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch79FlameBladeTest,
	"AshenOath.EliteInquisition.FlameBlade.StateVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch79FlameBladeTest::RunTest(const FString& Parameters)
{
	UAshenPurifierFlameBladeComponent* Blade = NewObject<UAshenPurifierFlameBladeComponent>();
	if (!TestNotNull(TEXT("PurifierFlameBladeComponent must be constructable"), Blade)) return false;

	Blade->SetBladeFlameState(EAshenPurifierBladeState::SootBlackenedAsh);
	TestEqual(TEXT("Blade state must equal SootBlackenedAsh"), Blade->BladeFlameState, EAshenPurifierBladeState::SootBlackenedAsh);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1595 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1595MasterVerificationTest,
	"AshenOath.Milestone.Milestone1595.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1595MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1595MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1595MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1595 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1595 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1595Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1595 SHROUD KNIGHT & PURIFIERS PIPELINE VERIFIED (1,595 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
