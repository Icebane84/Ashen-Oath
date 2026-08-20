// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1470: Serafina Empathic Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1470SynthesisOrchestrator.h"
#include "Companions/AshenSerafinaTransferenceComponent.h"
#include "Companions/AshenSerafinaBurnoutComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1470SerafinaEmpathicAutomationTest,
	"AshenOath.QA.SerafinaEmpathic.Milestone1470Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1470SerafinaEmpathicAutomationTest::RunTest(const FString& Parameters)
{
	UAshenSerafinaTransferenceComponent* Transference = NewObject<UAshenSerafinaTransferenceComponent>();
	if (!TestNotNull(TEXT("TransferenceComponent must be constructable"), Transference)) return false;

	const float Toll = Transference->CalculateTransferenceToll(20.0f, 0.5f);
	TestTrue(TEXT("Transference toll must be greater than raw healing"), Toll > 20.0f);

	UAshenSerafinaBurnoutComponent* Burnout = NewObject<UAshenSerafinaBurnoutComponent>();
	if (!TestNotNull(TEXT("BurnoutComponent must be constructable"), Burnout)) return false;

	Burnout->AddBurnout(75.0f);
	TestTrue(TEXT("Burnout must exceed 70.0 fever threshold"), Burnout->CurrentBurnout >= 70.0f);

	UAshenMilestone1470SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1470SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1470 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1470 validation must return true"), Orchestrator->ValidateMilestone1470Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1470 SERAFINA EMPATHIC SUITE VERIFIED ======"));
	return true;
}
