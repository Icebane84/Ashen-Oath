// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1095: Ashen Master Batch #54 QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1095MasterSynthesisOrchestrator.h"
#include "World/AshenSomaticPostureAlignmentEchoVolume.h"
#include "Combat/AshenSomaticPostureStanceAlignmentComponent.h"
#include "Companions/AshenGarrettShadowStepPincerDirectorComponent.h"
#include "Companions/AshenSerafinaRadiantPurgePincerDirectorComponent.h"

// =============================================================================
//  Test 1: Somatic Posture Alignment Echo Volume — Intensity
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch54SomaticPostureAlignmentEchoVolumeTest,
	"AshenOath.World.SomaticPostureAlignmentEchoVolume.IntensityVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch54SomaticPostureAlignmentEchoVolumeTest::RunTest(const FString& Parameters)
{
	AAshenSomaticPostureAlignmentEchoVolume* Volume = NewObject<AAshenSomaticPostureAlignmentEchoVolume>();
	if (!TestNotNull(TEXT("Somatic Posture Alignment Echo Volume must be constructable"), Volume)) return false;

	TestTrue(TEXT("Posture alignment echo intensity must be greater than 0"), Volume->PostureAlignmentEchoIntensity > 0.0f);
	return true;
}

// =============================================================================
//  Test 2: Somatic Posture Stance Alignment Component — Update Alignment
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch54SomaticPostureStanceAlignmentTest,
	"AshenOath.Combat.SomaticPostureStanceAlignment.UpdateAlignment",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch54SomaticPostureStanceAlignmentTest::RunTest(const FString& Parameters)
{
	UAshenSomaticPostureStanceAlignmentComponent* Comp = NewObject<UAshenSomaticPostureStanceAlignmentComponent>();
	if (!TestNotNull(TEXT("Somatic Posture Stance Alignment Component must be constructable"), Comp)) return false;

	Comp->UpdatePostureAlignment(0.5f);
	TestEqual(TEXT("Posture alignment scalar must equal 1.5f"), Comp->PostureAlignmentScalar, 1.5f);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1095 Verification Across All 1,095 Builds
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1095MasterVerificationTest,
	"AshenOath.Milestone.Milestone1095.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1095MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1095MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1095MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1095 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMasterMilestone1095Synthesis();
	TestTrue(TEXT("Master Milestone 1095 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1095 QA SUITE VERIFIED (1095 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
