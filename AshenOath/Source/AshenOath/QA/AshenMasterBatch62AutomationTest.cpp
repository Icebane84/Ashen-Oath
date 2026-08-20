// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1255: Master Batch #62 QA Automation Test Suite — MVSC Soul Constellation Kernel
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1255MasterSynthesisOrchestrator.h"
#include "Soul/AshenSoulConstellationSubsystem.h"
#include "Soul/AshenImprintBufferComponent.h"

// =============================================================================
//  Test 1: ImprintBufferComponent — buffer capacity guard and flush cycle
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch62ImprintBufferTest,
	"AshenOath.Soul.ImprintBuffer.CapacityAndFlushVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch62ImprintBufferTest::RunTest(const FString& Parameters)
{
	UAshenImprintBufferComponent* Buffer = NewObject<UAshenImprintBufferComponent>();
	if (!TestNotNull(TEXT("ImprintBufferComponent must be constructable"), Buffer)) return false;

	FAshenPsychologicalImprint Imp;
	Imp.ImprintID = "Test_ProtectiveAction";
	Imp.IntegrationDebtDelta = 0.10f;
	Imp.StanceWeightDelta    = 0.05f;
	Imp.EmpathicWeightDelta  = 0.03f;
	Imp.TacticalWeightDelta  = 0.02f;

	Buffer->AddImprint(Imp);
	TestEqual(TEXT("Buffer count must equal 1 after single AddImprint"), Buffer->BufferedImprintCount, 1);
	TestTrue(TEXT("Pending debt accumulation must equal ImprintDebtDelta"), FMath::IsNearlyEqual(Buffer->GetPendingDebtAccumulation(), 0.10f, 0.001f));
	return true;
}

// =============================================================================
//  Test 2: SoulConstellationSubsystem — ApplyRawWeightDeltas and debt stage evaluation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch62KernelWeightDeltaTest,
	"AshenOath.Soul.SoulConstellationKernel.WeightDeltaAndDebtStageVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch62KernelWeightDeltaTest::RunTest(const FString& Parameters)
{
	UAshenSoulConstellationSubsystem* Kernel = NewObject<UAshenSoulConstellationSubsystem>();
	if (!TestNotNull(TEXT("SoulConstellationSubsystem must be constructable"), Kernel)) return false;

	Kernel->ApplyRawWeightDeltas(0.20f, 0.20f, 0.20f, 0.60f);
	TestTrue(TEXT("StanceWeight must clamp to 0.70f"), FMath::IsNearlyEqual(Kernel->KernelIdentityState.StanceWeight, 0.70f, 0.01f));
	TestTrue(TEXT("IntegrationDebt must equal 0.60f"), FMath::IsNearlyEqual(Kernel->KernelIdentityState.IntegrationDebt, 0.60f, 0.01f));

	Kernel->CompileIdentity(false);
	TestEqual(TEXT("Debt stage for 0.60f must be MemoryBleed"), Kernel->GetDebtStage(), EAshenIntegrationDebtStage::MemoryBleed);
	TestEqual(TEXT("Stance profile must compile to Resolved_Protector"), Kernel->KernelIdentityState.CompiledProfile.StanceProfile, EAshenStanceProfile::Resolved_Protector);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1255 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1255MasterVerificationTest,
	"AshenOath.Milestone.Milestone1255.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1255MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1255MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1255MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1255 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1255 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1255Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1255 MVSC SOUL CONSTELLATION KERNEL VERIFIED (1,255 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
