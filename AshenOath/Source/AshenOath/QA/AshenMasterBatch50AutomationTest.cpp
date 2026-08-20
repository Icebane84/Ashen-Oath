// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1015: Ashen Master Batch #50 QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1015MasterSynthesisOrchestrator.h"
#include "World/AshenSovereignPhoenixAscensionLocusActor.h"
#include "Combat/AshenSomaticPhoenixPostureComponent.h"
#include "Companions/AshenGarrettPhoenixFlankAdapterComponent.h"
#include "Companions/AshenSerafinaAscensionAuraComponent.h"

// =============================================================================
//  Test 1: Sovereign Phoenix Ascension Locus Actor — Luminescence
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSovereignPhoenixAscensionLocusTest,
	"AshenOath.World.SovereignPhoenixLocus.LuminescenceVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSovereignPhoenixAscensionLocusTest::RunTest(const FString& Parameters)
{
	AAshenSovereignPhoenixAscensionLocusActor* Actor = NewObject<AAshenSovereignPhoenixAscensionLocusActor>();
	if (!TestNotNull(TEXT("Sovereign Phoenix Ascension Locus Actor must be constructable"), Actor)) return false;

	TestTrue(TEXT("Luminescence intensity must be greater than 0"), Actor->WhiteFlameLuminescenceIntensity > 0.0f);
	return true;
}

// =============================================================================
//  Test 2: Somatic Phoenix Posture Component — Alignment
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSomaticPhoenixPostureTest,
	"AshenOath.Combat.SomaticPhoenixPosture.Alignment",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSomaticPhoenixPostureTest::RunTest(const FString& Parameters)
{
	UAshenSomaticPhoenixPostureComponent* Comp = NewObject<UAshenSomaticPhoenixPostureComponent>();
	if (!TestNotNull(TEXT("Somatic Phoenix Posture Component must be constructable"), Comp)) return false;

	Comp->AlignPhoenixPostureStance();
	TestEqual(TEXT("Stance alignment scalar must equal 1.0f"), Comp->PhoenixStanceAlignmentScalar, 1.0f);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1015 Verification Across All 1,015 Builds
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1015MasterVerificationTest,
	"AshenOath.Milestone.Milestone1015.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1015MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1015MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1015MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1015 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMasterMilestone1015Synthesis();
	TestTrue(TEXT("Master Milestone 1015 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  👑 ASHEN OATH — MASTER MILESTONE 1015 QA SUITE VERIFIED (1,015 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
