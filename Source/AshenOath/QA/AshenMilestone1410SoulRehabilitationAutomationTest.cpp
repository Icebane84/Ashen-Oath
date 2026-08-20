// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1410: Soul Rehabilitation Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1410SynthesisOrchestrator.h"
#include "Soul/AshenImprintIntegrationRitualSubsystem.h"
#include "Soul/AshenRehabilitationTraitShiftEvaluator.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1410SoulRehabilitationAutomationTest,
	"AshenOath.QA.SoulRehabilitation.Milestone1410Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1410SoulRehabilitationAutomationTest::RunTest(const FString& Parameters)
{
	UAshenImprintIntegrationRitualSubsystem* Subsystem = NewObject<UAshenImprintIntegrationRitualSubsystem>();
	if (!TestNotNull(TEXT("RitualSubsystem must be constructable"), Subsystem)) return false;

	Subsystem->ActiveImprintCount = 3;
	Subsystem->PurifyOldestImprint();
	TestEqual(TEXT("Remaining imprint count must equal 2"), Subsystem->ActiveImprintCount, 2);

	UAshenRehabilitationTraitShiftEvaluator* Evaluator = NewObject<UAshenRehabilitationTraitShiftEvaluator>();
	if (!TestNotNull(TEXT("TraitShiftEvaluator must be constructable"), Evaluator)) return false;

	Evaluator->ApplyPermanentRehabilitationTraitBonuses(1.0f);
	TestTrue(TEXT("Poise bonus multiplier must equal 1.05f"), FMath::IsNearlyEqual(Evaluator->PermanentPoiseBonusMultiplier, 1.05f, 0.001f));

	UAshenMilestone1410SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1410SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1410 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1410 validation must return true"), Orchestrator->ValidateMilestone1410Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1410 SOUL REHABILITATION SUITE VERIFIED ======"));
	return true;
}
