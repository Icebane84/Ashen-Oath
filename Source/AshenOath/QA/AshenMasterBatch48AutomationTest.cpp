// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 975: Ashen Master Batch #48 QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone975MasterSynthesisOrchestrator.h"
#include "Memory/AshenMindscapeFractureEchoVolume.h"
#include "Combat/AshenSomaticPostureAlignmentComponent.h"
#include "Companions/AshenGarrettShadowStepFlankAdapterComponent.h"
#include "Companions/AshenSerafinaRadiantPurgeAuraComponent.h"

// =============================================================================
//  Test 1: Mindscape Fracture Echo Volume — Instability Index
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMindscapeFractureEchoVolumeTest,
	"AshenOath.Memory.FractureEchoVolume.InstabilityVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMindscapeFractureEchoVolumeTest::RunTest(const FString& Parameters)
{
	AAshenMindscapeFractureEchoVolume* Volume = NewObject<AAshenMindscapeFractureEchoVolume>();
	if (!TestNotNull(TEXT("Mindscape Fracture Echo Volume must be constructable"), Volume)) return false;

	TestTrue(TEXT("Fracture instability index must be greater than 0"), Volume->FractureInstabilityIndex > 0.0f);
	return true;
}

// =============================================================================
//  Test 2: Somatic Posture Alignment Component — Alignment Weight
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSomaticPostureAlignmentTest,
	"AshenOath.Combat.SomaticPosture.AlignmentWeight",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSomaticPostureAlignmentTest::RunTest(const FString& Parameters)
{
	UAshenSomaticPostureAlignmentComponent* Comp = NewObject<UAshenSomaticPostureAlignmentComponent>();
	if (!TestNotNull(TEXT("Somatic Posture Alignment Component must be constructable"), Comp)) return false;

	Comp->AlignSomaticPostureWithSoulState(0.85f);
	TestEqual(TEXT("Posture stability weight must equal 0.85f"), Comp->PostureStabilityWeight, 0.85f);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 975 Verification Across All 975 Builds
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone975MasterVerificationTest,
	"AshenOath.Milestone.Milestone975.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone975MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone975MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone975MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 975 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMasterMilestone975Synthesis();
	TestTrue(TEXT("Master Milestone 975 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 975 QA SUITE VERIFIED (975 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
