// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 685: Ashen Aegis Mechanics & Sanctuary Stain Cleanser Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenBehemothKnockdownInterceptionEvaluator.h"
#include "AshenMartyrGuardCorruptionSpikeCalculator.h"
#include "AshenSpiritualStainSanctuaryCleanser.h"

// =============================================================================
//  Test 1: Behemoth Knockdown Interception Evaluator — Evaluation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBehemothKnockdownInterceptionEvaluatorTest,
	"AshenOath.AegisBehemoth.Evaluator.EvaluateKnockdown",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBehemothKnockdownInterceptionEvaluatorTest::RunTest(const FString& Parameters)
{
	UAshenBehemothKnockdownInterceptionEvaluator* Eval = NewObject<UAshenBehemothKnockdownInterceptionEvaluator>();
	if (!TestNotNull(TEXT("BehemothKnockdownInterceptionEvaluator must be constructable"), Eval)) return false;

	TestTrue(TEXT("Impulse 500.0 with 50.0 stamina must negate knockdown"), Eval->EvaluateBehemothKnockdownInterception(500.0f, 50.0f));

	return true;
}

// =============================================================================
//  Test 2: Martyr Guard Corruption Spike Calculator — Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMartyrGuardCorruptionSpikeCalculatorTest,
	"AshenOath.MartyrGuardCorruption.Calculator.CalculateSpike",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMartyrGuardCorruptionSpikeCalculatorTest::RunTest(const FString& Parameters)
{
	UAshenMartyrGuardCorruptionSpikeCalculator* Calc = NewObject<UAshenMartyrGuardCorruptionSpikeCalculator>();
	if (!TestNotNull(TEXT("MartyrGuardCorruptionSpikeCalculator must be constructable"), Calc)) return false;

	const float Spike = Calc->CalculateMartyrCorruptionSpike(100.0f, 20.0f);
	TestEqual(TEXT("Calculated Corruption Spike must equal 15.0"), Spike, 15.0f);

	return true;
}

// =============================================================================
//  Test 3: Spiritual Stain Sanctuary Cleanser — Cleanse Execution
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSpiritualStainSanctuaryCleanserTest,
	"AshenOath.SanctuaryCleanser.Subsystem.CleanseStain",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSpiritualStainSanctuaryCleanserTest::RunTest(const FString& Parameters)
{
	UAshenSpiritualStainSanctuaryCleanser* Cleanser = NewObject<UAshenSpiritualStainSanctuaryCleanser>();
	if (!TestNotNull(TEXT("SpiritualStainSanctuaryCleanser must be constructable"), Cleanser)) return false;

	TestTrue(TEXT("Sanctuary cleanse with 100 resources and 30% stain must succeed"), Cleanser->CleanseStainAtSanctuary(30.0f, 100));

	return true;
}
