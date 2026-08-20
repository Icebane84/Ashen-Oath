// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1510: Advanced Combat Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1510SynthesisOrchestrator.h"
#include "Combat/AshenParryCounterExecutionGASAbility.h"
#include "Combat/AshenUnchainedBerserkGASAbility.h"
#include "Combat/AshenParryPoiseImpactComponent.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1510AdvancedCombatAutomationTest,
	"AshenOath.QA.AdvancedCombat.Milestone1510Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1510AdvancedCombatAutomationTest::RunTest(const FString& Parameters)
{
	UAshenParryCounterExecutionGASAbility* ParryAbility = NewObject<UAshenParryCounterExecutionGASAbility>();
	if (!TestNotNull(TEXT("ParryAbility must be constructable"), ParryAbility)) return false;

	TestTrue(TEXT("Parry window trigger must succeed"), ParryAbility->TriggerParryWindow());

	UAshenUnchainedBerserkGASAbility* BerserkAbility = NewObject<UAshenUnchainedBerserkGASAbility>();
	if (!TestNotNull(TEXT("BerserkAbility must be constructable"), BerserkAbility)) return false;

	TestTrue(TEXT("Unchained berserk activation must succeed"), BerserkAbility->ActivateUnchainedBerserk());

	UAshenParryPoiseImpactComponent* PoiseComp = NewObject<UAshenParryPoiseImpactComponent>();
	if (!TestNotNull(TEXT("ParryPoiseImpactComponent must be constructable"), PoiseComp)) return false;

	const float PoiseDmg = PoiseComp->CalculatePostureDamageDealt(1.5f);
	TestEqual(TEXT("Calculated posture damage must equal 120.0f"), PoiseDmg, 120.0f);

	UAshenMilestone1510SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1510SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1510 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1510 validation must return true"), Orchestrator->ValidateMilestone1510Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1510 ADVANCED COMBAT SUITE VERIFIED ======"));
	return true;
}
