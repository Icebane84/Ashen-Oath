// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1490: Unreliable Narrator Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1490SynthesisOrchestrator.h"
#include "Memory/AshenUnreliableNarratorEnvironmentalVolume.h"
#include "Memory/AshenUnreliableNarratorCombatComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1490UnreliableNarratorAutomationTest,
	"AshenOath.QA.UnreliableNarrator.Milestone1490Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1490UnreliableNarratorAutomationTest::RunTest(const FString& Parameters)
{
	AAshenUnreliableNarratorEnvironmentalVolume* Volume = NewObject<AAshenUnreliableNarratorEnvironmentalVolume>();
	if (!TestNotNull(TEXT("NarratorEnvironmentalVolume must be constructable"), Volume)) return false;

	Volume->EvaluateSanityDistortion(0.10f, 0.90f);
	TestEqual(TEXT("Hallucination state must be Reality_Collapsed"), Volume->CurrentHallucinationState, EAshenEnvironmentalHallucinationState::Reality_Collapsed);

	UAshenUnreliableNarratorCombatComponent* CombatComp = NewObject<UAshenUnreliableNarratorCombatComponent>();
	if (!TestNotNull(TEXT("CombatComponent must be constructable"), CombatComp)) return false;

	CombatComp->SpawnCombatMirage(FVector(100.0f, 0.0f, 0.0f));
	TestEqual(TEXT("Active mirage count must equal 1"), CombatComp->ActiveMirageCount, 1);

	UAshenMilestone1490SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1490SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1490 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1490 validation must return true"), Orchestrator->ValidateMilestone1490Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1490 UNRELIABLE NARRATOR SUITE VERIFIED ======"));
	return true;
}
