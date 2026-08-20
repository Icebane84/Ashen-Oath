// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1630: Party Finisher Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1630SynthesisOrchestrator.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "Combat/AshenFinisherTraumaResolverComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1630PartyFinisherAutomationTest,
	"AshenOath.QA.PartyFinisher.Milestone1630Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1630PartyFinisherAutomationTest::RunTest(const FString& Parameters)
{
	UAshenPartySyncFinisherSubsystem* FinisherSubsystem = NewObject<UAshenPartySyncFinisherSubsystem>();
	if (!TestNotNull(TEXT("PartySyncFinisherSubsystem must be constructable"), FinisherSubsystem)) return false;

	// Test 1: Priority Matrix Evaluation
	const EAshenPartyFinisherType DarkIntervention = FinisherSubsystem->EvaluateFinisherEligibility(true, 0.0f, false, 1);
	TestEqual(TEXT("Crisis Dark Mode must select ShepherdsIntervention"), DarkIntervention, EAshenPartyFinisherType::ShepherdsIntervention);

	const EAshenPartyFinisherType Nova = FinisherSubsystem->EvaluateFinisherEligibility(false, 0.85f, false, 1);
	TestEqual(TEXT("Serafina Burnout >= 70% must select EmpathicConduitNova"), Nova, EAshenPartyFinisherType::EmpathicConduitNova);

	const EAshenPartyFinisherType Triangle = FinisherSubsystem->EvaluateFinisherEligibility(false, 0.20f, false, 4);
	TestEqual(TEXT("4 broken enemies must select AshenTriangleCollapse"), Triangle, EAshenPartyFinisherType::AshenTriangleCollapse);

	const EAshenPartyFinisherType Sentinel = FinisherSubsystem->EvaluateFinisherEligibility(false, 0.20f, true, 1);
	TestEqual(TEXT("Armored enemy must select SentinelsEclipse"), Sentinel, EAshenPartyFinisherType::SentinelsEclipse);

	const EAshenPartyFinisherType DefaultCleave = FinisherSubsystem->EvaluateFinisherEligibility(false, 0.20f, false, 1);
	TestEqual(TEXT("Default conditions must select TripartiteResonantCleave"), DefaultCleave, EAshenPartyFinisherType::TripartiteResonantCleave);

	// Test 2: Trauma Resolver Paydown
	UAshenFinisherTraumaResolverComponent* TraumaResolver = NewObject<UAshenFinisherTraumaResolverComponent>();
	if (!TestNotNull(TEXT("FinisherTraumaResolverComponent must be constructable"), TraumaResolver)) return false;

	TraumaResolver->ResolveTraumaPaydown(EAshenPartyFinisherType::TripartiteResonantCleave, 100.0f, 50.0f);
	TestTrue(TEXT("bWhispersSilenced must be true after Tripartite Cleave"), TraumaResolver->bWhispersSilenced);

	UAshenMilestone1630SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1630SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1630 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1630 validation must return true"), Orchestrator->ValidateMilestone1630Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1630 PARTY FINISHER SUITE VERIFIED ======"));
	return true;
}
