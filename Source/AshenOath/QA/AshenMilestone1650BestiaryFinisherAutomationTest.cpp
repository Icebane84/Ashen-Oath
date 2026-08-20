// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1650: Bestiary Finisher Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1650SynthesisOrchestrator.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "Combat/AshenEchoMaimerPhantomAnchorComponent.h"
#include "Combat/AshenGuiltStitcherSutureComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1650BestiaryFinisherAutomationTest,
	"AshenOath.QA.BestiaryFinisher.Milestone1650Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1650BestiaryFinisherAutomationTest::RunTest(const FString& Parameters)
{
	// Test 1: Echo-Maimer Phantom Collapse
	UAshenEchoMaimerPhantomAnchorComponent* EchoComp = NewObject<UAshenEchoMaimerPhantomAnchorComponent>();
	if (!TestNotNull(TEXT("EchoMaimerPhantomAnchorComponent must be constructable"), EchoComp)) return false;

	EchoComp->SpawnPhantomHitbox(FVector(100.0f, 200.0f, 0.0f));
	EchoComp->SpawnPhantomHitbox(FVector(300.0f, 400.0f, 0.0f));
	TestEqual(TEXT("ActivePhantomHitboxes must equal 2"), EchoComp->ActivePhantomHitboxes, 2);

	EchoComp->CollapseAllPhantomTimelines();
	TestEqual(TEXT("ActivePhantomHitboxes must equal 0 after collapse"), EchoComp->ActivePhantomHitboxes, 0);

	// Test 2: Guilt-Stitcher Suture Snip
	UAshenGuiltStitcherSutureComponent* SutureComp = NewObject<UAshenGuiltStitcherSutureComponent>();
	if (!TestNotNull(TEXT("GuiltStitcherSutureComponent must be constructable"), SutureComp)) return false;

	SutureComp->EstablishSympatheticSuture();
	TestTrue(TEXT("bIsSutureActive must equal true"), SutureComp->bIsSutureActive);

	SutureComp->SeverSympatheticSuture();
	TestFalse(TEXT("bIsSutureActive must equal false after sever"), SutureComp->bIsSutureActive);

	UAshenMilestone1650SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1650SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1650 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1650 validation must return true"), Orchestrator->ValidateMilestone1650Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1650 BESTIARY FINISHER SUITE VERIFIED ======"));
	return true;
}
