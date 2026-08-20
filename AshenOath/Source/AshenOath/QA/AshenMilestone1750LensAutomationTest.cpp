// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1750: Interpretive Lens & Identity Compilation Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1750SynthesisOrchestrator.h"
#include "Soul/AshenInterpretiveLensSubsystem.h"
#include "Soul/AshenIdentityCompilerComponent.h"
#include "World/AshenLensSanctuaryPillarActor.h"
#include "Combat/AshenLensBuffManagerComponent.h"
#include "Combat/AshenInterpretiveLensGASAbility.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1750LensAutomationTest,
	"AshenOath.QA.Lens.Milestone1750Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1750LensAutomationTest::RunTest(const FString& Parameters)
{
	// Test 1: Lens Subsystem Bias Evaluation
	UAshenInterpretiveLensSubsystem* Subsystem = NewObject<UAshenInterpretiveLensSubsystem>();
	if (!TestNotNull(TEXT("InterpretiveLensSubsystem must be constructable"), Subsystem)) return false;
	Subsystem->SetActiveLens(EInterpretiveLens::Accountability);
	float GWeight = 1.0f, SWeight = 1.0f;
	Subsystem->ApplyInterpretiveFilter(GWeight, SWeight);
	TestEqual(TEXT("Garrett trust bias must equal 1.15f"), GWeight, 1.15f);

	// Test 2: Identity Compiler Component
	UAshenIdentityCompilerComponent* Compiler = NewObject<UAshenIdentityCompilerComponent>();
	if (!TestNotNull(TEXT("IdentityCompilerComponent must be constructable"), Compiler)) return false;
	FSoulStateVector Compiled = Compiler->CompileIdentity(0.8f, 0.2f, 0.4f, 0.5f, 0.5f, EInterpretiveLens::Grace);
	TestEqual(TEXT("Compiled resolve must equal 0.8f"), Compiled.Resolve, 0.8f);

	// Test 3: Sanctuary Pillar Actor
	AAshenLensSanctuaryPillarActor* Pillar = NewObject<AAshenLensSanctuaryPillarActor>();
	if (!TestNotNull(TEXT("LensSanctuaryPillarActor must be constructable"), Pillar)) return false;
	TestTrue(TEXT("CommuneWithPillar must return true"), Pillar->CommuneWithPillar(nullptr));

	// Test 4: Lens Buff Manager Component
	UAshenLensBuffManagerComponent* BuffManager = NewObject<UAshenLensBuffManagerComponent>();
	if (!TestNotNull(TEXT("LensBuffManagerComponent must be constructable"), BuffManager)) return false;
	BuffManager->ApplyLensGameplayBuffs(EInterpretiveLens::Utility);
	TestEqual(TEXT("ThreatPerceptionModifier must equal 0.30f"), BuffManager->ThreatPerceptionModifier, 0.30f);

	// Test 5: Lens GAS Ability
	UAshenInterpretiveLensGASAbility* Ability = NewObject<UAshenInterpretiveLensGASAbility>();
	if (!TestNotNull(TEXT("InterpretiveLensGASAbility must be constructable"), Ability)) return false;
	TestEqual(TEXT("LensAuraRadius must equal 900.0f"), Ability->LensAuraRadius, 900.0f);

	UAshenMilestone1750SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1750SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1750 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1750 validation must return true"), Orchestrator->ValidateMilestone1750Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1750 INTERPRETIVE LENS SUITE VERIFIED ======"));
	return true;
}
