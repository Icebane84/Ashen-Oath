// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1290: Companion Synergy Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1290SynthesisOrchestrator.h"
#include "Companions/AshenCompanionResonanceSyncEvaluator.h"
#include "Companions/AshenTripartiteFatigueBurnComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1290CompanionSynergyAutomationTest,
	"AshenOath.QA.CompanionSynergy.Milestone1290Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1290CompanionSynergyAutomationTest::RunTest(const FString& Parameters)
{
	UAshenCompanionResonanceSyncEvaluator* Evaluator = NewObject<UAshenCompanionResonanceSyncEvaluator>();
	if (!TestNotNull(TEXT("ResonanceSyncEvaluator must be constructable"), Evaluator)) return false;

	const bool bSync = Evaluator->EvaluateResonanceSync(0.60f, 0.55f, 0.20f, 0.20f, 0.80f);
	TestTrue(TEXT("ResonanceSync must be active when trust delta < 0.15, fatigue < 0.4, resolve > 0.5"), bSync);

	UAshenTripartiteFatigueBurnComponent* FatigueComp = NewObject<UAshenTripartiteFatigueBurnComponent>();
	if (!TestNotNull(TEXT("FatigueBurnComponent must be constructable"), FatigueComp)) return false;
	FatigueComp->AccumulateFatigue(0.75f, 0.10f, 0.10f);
	TestTrue(TEXT("Garrett must be vulnerable at fatigue >= 0.7"), FatigueComp->IsCompanionVulnerable("Garrett"));

	UAshenMilestone1290SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1290SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1290 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1290 validation must return true"), Orchestrator->ValidateMilestone1290Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1290 COMPANION SYNERGY SUITE VERIFIED ======"));
	return true;
}
