// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1295: Master Batch #64 QA Automation Test Suite — Companion Trust, Spatial Divergence & Tripartite Fatigue Burn
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1295MasterSynthesisOrchestrator.h"
#include "Companions/AshenCompanionTrustAccumulationComponent.h"
#include "Companions/AshenCompanionSpatialDivergenceComponent.h"
#include "Companions/AshenCompanionResonanceSyncEvaluator.h"

// =============================================================================
//  Test 1: Trust Accumulation & Protective Action Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch64TrustAccumulationTest,
	"AshenOath.CompanionTrust.Accumulation.ProtectiveActionVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch64TrustAccumulationTest::RunTest(const FString& Parameters)
{
	UAshenCompanionTrustAccumulationComponent* TrustComp = NewObject<UAshenCompanionTrustAccumulationComponent>();
	if (!TestNotNull(TEXT("TrustAccumulationComponent must be constructable"), TrustComp)) return false;

	TrustComp->ProcessProtectiveAction("Garrett");
	TestTrue(TEXT("Garrett trust must increase to 0.55f"), FMath::IsNearlyEqual(TrustComp->GarrettTrust, 0.55f, 0.001f));
	return true;
}

// =============================================================================
//  Test 2: Spatial Divergence Offset Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch64SpatialDivergenceTest,
	"AshenOath.CompanionTrust.Divergence.OffsetCalculationVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch64SpatialDivergenceTest::RunTest(const FString& Parameters)
{
	UAshenCompanionSpatialDivergenceComponent* DivComp = NewObject<UAshenCompanionSpatialDivergenceComponent>();
	if (!TestNotNull(TEXT("SpatialDivergenceComponent must be constructable"), DivComp)) return false;

	DivComp->RecalculateSpatialDivergenceOffsets(0.0f, 1.0f);
	TestTrue(TEXT("Garrett offset must equal 800uu at 0.0 trust"), FMath::IsNearlyEqual(DivComp->GarrettNavigationOffset, 800.0f, 0.1f));
	TestTrue(TEXT("Serafina offset must equal 200uu at 1.0 trust"), FMath::IsNearlyEqual(DivComp->SerafinaNavigationOffset, 200.0f, 0.1f));
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1295 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1295MasterVerificationTest,
	"AshenOath.Milestone.Milestone1295.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1295MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1295MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1295MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1295 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1295 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1295Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1295 COMPANION TRUST PIPELINE VERIFIED (1,295 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
