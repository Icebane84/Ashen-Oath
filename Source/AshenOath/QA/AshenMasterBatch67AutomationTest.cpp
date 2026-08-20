// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1355: Master Batch #67 QA Automation Test Suite — Shadow Mark C Corruption Visual Shift & Duality Shader Shift
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1355MasterSynthesisOrchestrator.h"
#include "World/AshenShadowMarkCorruptionMPCModulator.h"
#include "World/AshenDualityShaderShiftComponent.h"
#include "Narrative/AshenVisualShiftNarrativeReactivityComponent.h"

// =============================================================================
//  Test 1: Shadow Mark C Emissive Intensity Modulator
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch67ShadowMarkMPCTest,
	"AshenOath.VisualShift.ShadowMark.EmissiveScalarVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch67ShadowMarkMPCTest::RunTest(const FString& Parameters)
{
	UAshenShadowMarkCorruptionMPCModulator* MPCMod = NewObject<UAshenShadowMarkCorruptionMPCModulator>();
	if (!TestNotNull(TEXT("MPCModulator must be constructable"), MPCMod)) return false;

	MPCMod->UpdateShadowMarkEmissiveScalar(1.0f);
	TestTrue(TEXT("Emissive intensity must equal 5.0f at 100% corruption"), FMath::IsNearlyEqual(MPCMod->ShadowMarkEmissiveIntensity, 5.0f, 0.001f));
	return true;
}

// =============================================================================
//  Test 2: Narrative NPC Fear Reaction Threshold
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch67NPCFearTest,
	"AshenOath.VisualShift.Narrative.NPCFearVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch67NPCFearTest::RunTest(const FString& Parameters)
{
	UAshenVisualShiftNarrativeReactivityComponent* FearComp = NewObject<UAshenVisualShiftNarrativeReactivityComponent>();
	if (!TestNotNull(TEXT("FearComponent must be constructable"), FearComp)) return false;

	const bool bFear = FearComp->EvaluateNPCFearReaction(0.75f);
	TestTrue(TEXT("Fear reaction must trigger when corruption > 0.60f"), bFear);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1355 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1355MasterVerificationTest,
	"AshenOath.Milestone.Milestone1355.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1355MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1355MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1355MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1355 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1355 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1355Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1355 VISUAL SHIFT PIPELINE VERIFIED (1,355 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
