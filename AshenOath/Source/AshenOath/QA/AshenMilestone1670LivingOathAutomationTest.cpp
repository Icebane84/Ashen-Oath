// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1670: Living Oath Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1670SynthesisOrchestrator.h"
#include "Soul/AshenLivingOathSubsystem.h"
#include "Combat/AshenOathbringerMindscapeComponent.h"
#include "Soul/AshenOathbreakerConsequenceComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1670LivingOathAutomationTest,
	"AshenOath.QA.LivingOath.Milestone1670Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1670LivingOathAutomationTest::RunTest(const FString& Parameters)
{
	// Test 1: Oathbringer Morph
	UAshenOathbringerMindscapeComponent* MorphComp = NewObject<UAshenOathbringerMindscapeComponent>();
	if (!TestNotNull(TEXT("OathbringerMindscapeComponent must be constructable"), MorphComp)) return false;

	MorphComp->SetSwordMorphState(EAshenSwordMorphState::BloodParasite);
	TestEqual(TEXT("MorphState must equal BloodParasite"), MorphComp->MorphState, EAshenSwordMorphState::BloodParasite);

	// Test 2: Oathbreaker Consequences
	UAshenOathbreakerConsequenceComponent* ConsequenceComp = NewObject<UAshenOathbreakerConsequenceComponent>();
	if (!TestNotNull(TEXT("OathbreakerConsequenceComponent must be constructable"), ConsequenceComp)) return false;

	ConsequenceComp->ApplyOathbreakerConsequences();
	TestTrue(TEXT("bIsSwordRebelling must equal true"), ConsequenceComp->bIsSwordRebelling);

	UAshenMilestone1670SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1670SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1670 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1670 validation must return true"), Orchestrator->ValidateMilestone1670Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1670 LIVING OATH SUITE VERIFIED ======"));
	return true;
}
