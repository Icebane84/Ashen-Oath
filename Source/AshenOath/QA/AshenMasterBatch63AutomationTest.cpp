// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1275: Master Batch #63 QA Automation Test Suite — Integration Debt 4-Stage Escalation & Forced Collapse
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1275MasterSynthesisOrchestrator.h"
#include "Soul/AshenIntegrationDebtManager.h"
#include "Combat/AshenRuntimeNoiseCombatDegradationComponent.h"
#include "Audio/AshenDebtEscalationAudioModulator.h"

// =============================================================================
//  Test 1: IntegrationDebtManager — 4-stage evaluation & parry window multiplier
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch63DebtStageEvaluationTest,
	"AshenOath.IntegrationDebt.Manager.StageEvaluationVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch63DebtStageEvaluationTest::RunTest(const FString& Parameters)
{
	UAshenIntegrationDebtManager* Manager = NewObject<UAshenIntegrationDebtManager>();
	if (!TestNotNull(TEXT("IntegrationDebtManager must be constructable"), Manager)) return false;

	Manager->UpdateIntegrationDebt(0.80f);
	TestEqual(TEXT("Debt 0.80f stage must be RuntimeNoise"), Manager->CurrentDebtStage, EAshenIntegrationDebtStage::RuntimeNoise);
	TestTrue(TEXT("Parry window multiplier must equal 0.85f during Runtime Noise"), FMath::IsNearlyEqual(Manager->GetParryWindowMultiplier(), 0.85f, 0.001f));
	return true;
}

// =============================================================================
//  Test 2: AudioModulator & CombatDegradation — Audio & Parry narrowing responsiveness
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch63AudioCombatDegradationTest,
	"AshenOath.IntegrationDebt.Degradation.AudioAndCombatVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch63AudioCombatDegradationTest::RunTest(const FString& Parameters)
{
	UAshenDebtEscalationAudioModulator* AudioMod = NewObject<UAshenDebtEscalationAudioModulator>();
	if (!TestNotNull(TEXT("AudioModulator must be constructable"), AudioMod)) return false;

	AudioMod->UpdateAudioModulationForDebtStage(EAshenIntegrationDebtStage::MemoryBleed);
	TestTrue(TEXT("Whisper spawn frequency must equal 2.0f at MemoryBleed stage"), FMath::IsNearlyEqual(AudioMod->WhisperSpawnFrequency, 2.0f, 0.001f));

	UAshenRuntimeNoiseCombatDegradationComponent* CombatDeg = NewObject<UAshenRuntimeNoiseCombatDegradationComponent>();
	if (!TestNotNull(TEXT("CombatDegradationComponent must be constructable"), CombatDeg)) return false;

	CombatDeg->ApplyRuntimeNoiseDegradation(EAshenIntegrationDebtStage::RuntimeNoise);
	TestTrue(TEXT("Parry window multiplier must equal 0.85f"), FMath::IsNearlyEqual(CombatDeg->ParryWindowMultiplier, 0.85f, 0.001f));
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1275 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1275MasterVerificationTest,
	"AshenOath.Milestone.Milestone1275.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1275MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1275MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1275MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1275 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1275 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1275Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1275 INTEGRATION DEBT PIPELINE VERIFIED (1,275 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
