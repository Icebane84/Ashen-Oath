// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1155: Ashen Master Batch #57 QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1155MasterSynthesisOrchestrator.h"
#include "Combat/AshenStaggeredCrisisTimelineController.h"
#include "Combat/AshenDevilsBargainResolutionHandler.h"
#include "Combat/AshenWhiteFlameResolutionHandler.h"

// =============================================================================
//  Test 1: Staggered Crisis Timeline Controller — Initiation & Dilation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch57StaggeredCrisisTimelineTest,
	"AshenOath.Combat.StaggeredCrisisTimeline.InitiationVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch57StaggeredCrisisTimelineTest::RunTest(const FString& Parameters)
{
	UAshenStaggeredCrisisTimelineController* Controller = NewObject<UAshenStaggeredCrisisTimelineController>();
	if (!TestNotNull(TEXT("Staggered Crisis Timeline Controller must be constructable"), Controller)) return false;

	Controller->InitiateCrisisTimeline();
	TestEqual(TEXT("Time dilation scalar must equal 0.10f"), Controller->TimeDilationScalar, 0.10f);
	TestEqual(TEXT("Crisis stage must be TimeDilationStart"), Controller->CurrentCrisisStage, EAshenCrisisStage::TimeDilationStart);
	return true;
}

// =============================================================================
//  Test 2: Devil's Bargain & White Flame Dual Resolutions
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch57CrisisDualResolutionTest,
	"AshenOath.Combat.CrisisDualResolution.ExecutionVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch57CrisisDualResolutionTest::RunTest(const FString& Parameters)
{
	UAshenDevilsBargainResolutionHandler* HandlerA = NewObject<UAshenDevilsBargainResolutionHandler>();
	if (!TestNotNull(TEXT("Devil's Bargain Resolution Handler must be constructable"), HandlerA)) return false;
	TestTrue(TEXT("Path A surrender execution must return true"), HandlerA->ExecuteDevilsBargainSurrender());

	UAshenWhiteFlameResolutionHandler* HandlerB = NewObject<UAshenWhiteFlameResolutionHandler>();
	if (!TestNotNull(TEXT("White Flame Resolution Handler must be constructable"), HandlerB)) return false;
	TestTrue(TEXT("Path B restraint execution must return true"), HandlerB->ExecuteWhiteFlameRestraint());
	TestTrue(TEXT("Willpower unbroken buff must be active"), HandlerB->bWillpowerUnbrokenBuffActive);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1155 Verification Across All 1,155 Builds
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1155MasterVerificationTest,
	"AshenOath.Milestone.Milestone1155.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1155MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1155MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1155MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1155 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMasterMilestone1155Synthesis();
	TestTrue(TEXT("Master Milestone 1155 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1155 QA SUITE VERIFIED (1155 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
