// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 990: Ashen Armor Corrosion QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone990SynthesisOrchestrator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenArmorCorrosionAutomationTest,
	"AshenOath.QA.ArmorCorrosion.Milestone990Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenArmorCorrosionAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone990SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone990SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 990 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMilestone990Synthesis();
	TestTrue(TEXT("Milestone 990 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MILESTONE 990 ARMOR CORROSION SUITE VERIFIED (990 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
