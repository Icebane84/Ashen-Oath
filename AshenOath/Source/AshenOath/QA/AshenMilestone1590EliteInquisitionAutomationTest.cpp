// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1590: Elite Inquisition Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1590SynthesisOrchestrator.h"
#include "AI/AshenShroudKnightCharacter.h"
#include "Combat/AshenPurifierFlameBladeComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1590EliteInquisitionAutomationTest,
	"AshenOath.QA.EliteInquisition.Milestone1590Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1590EliteInquisitionAutomationTest::RunTest(const FString& Parameters)
{
	AAshenShroudKnightCharacter* Knight = NewObject<AAshenShroudKnightCharacter>();
	if (!TestNotNull(TEXT("ShroudKnightCharacter must be constructable"), Knight)) return false;

	Knight->InitiateSpectralPhase();
	TestEqual(TEXT("CurrentState must equal SpectralPhasing"), Knight->CurrentState, EAshenShroudSpiritState::SpectralPhasing);

	UAshenPurifierFlameBladeComponent* Blade = NewObject<UAshenPurifierFlameBladeComponent>();
	if (!TestNotNull(TEXT("PurifierFlameBladeComponent must be constructable"), Blade)) return false;

	Blade->SetBladeFlameState(EAshenPurifierBladeState::HolyWhiteFlame);
	TestEqual(TEXT("BladeFlameState must equal HolyWhiteFlame"), Blade->BladeFlameState, EAshenPurifierBladeState::HolyWhiteFlame);

	UAshenMilestone1590SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1590SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1590 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1590 validation must return true"), Orchestrator->ValidateMilestone1590Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1590 ELITE INQUISITION SUITE VERIFIED ======"));
	return true;
}
