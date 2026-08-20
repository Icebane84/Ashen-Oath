// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1350: Duality Shader Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1350SynthesisOrchestrator.h"
#include "World/AshenShadowMarkCorruptionMPCModulator.h"
#include "World/AshenDualityShaderShiftComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1350DualityShaderAutomationTest,
	"AshenOath.QA.DualityShader.Milestone1350Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1350DualityShaderAutomationTest::RunTest(const FString& Parameters)
{
	UAshenShadowMarkCorruptionMPCModulator* MPCMod = NewObject<UAshenShadowMarkCorruptionMPCModulator>();
	if (!TestNotNull(TEXT("ShadowMarkMPCModulator must be constructable"), MPCMod)) return false;

	MPCMod->UpdateShadowMarkEmissiveScalar(0.80f);
	TestTrue(TEXT("Emissive intensity must equal 4.0f at 80% corruption"), FMath::IsNearlyEqual(MPCMod->ShadowMarkEmissiveIntensity, 4.0f, 0.001f));

	UAshenDualityShaderShiftComponent* ShiftComp = NewObject<UAshenDualityShaderShiftComponent>();
	if (!TestNotNull(TEXT("DualityShaderShiftComponent must be constructable"), ShiftComp)) return false;

	ShiftComp->SetDualityBlendRatio(0.65f);
	TestTrue(TEXT("Blend ratio must equal 0.65f"), FMath::IsNearlyEqual(ShiftComp->CurrentDualityBlendRatio, 0.65f, 0.001f));

	UAshenMilestone1350SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1350SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1350 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1350 validation must return true"), Orchestrator->ValidateMilestone1350Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1350 DUALITY SHADER SUITE VERIFIED ======"));
	return true;
}
