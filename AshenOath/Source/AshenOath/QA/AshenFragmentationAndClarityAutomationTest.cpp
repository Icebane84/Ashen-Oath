// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 625: Ashen Separation Velocity, Plausible Destructiveness & Narrative Entropy Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenSeparationVelocityCalculator.h"
#include "AshenPlausibleDestructivenessEvaluator.h"
#include "AshenEntropyOfMeaningSubsystem.h"

// =============================================================================
//  Test 1: Separation Velocity Calculator — Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSeparationVelocityCalculatorTest,
	"AshenOath.SeparationVelocity.Calculator.Calculate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSeparationVelocityCalculatorTest::RunTest(const FString& Parameters)
{
	UAshenSeparationVelocityCalculator* Calc = NewObject<UAshenSeparationVelocityCalculator>();
	if (!TestNotNull(TEXT("SeparationVelocityCalculator must be constructable"), Calc)) return false;

	const float Velocity = Calc->CalculateSeparationVelocity(0.8f, 3.0f);
	TestEqual(TEXT("Calculated Separation Velocity must equal 1.8"), Velocity, 1.8f);

	return true;
}

// =============================================================================
//  Test 2: Plausible Destructiveness Evaluator — Whisper Selection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPlausibleDestructivenessEvaluatorTest,
	"AshenOath.PlausibleDestructiveness.Evaluator.SelectWhisper",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPlausibleDestructivenessEvaluatorTest::RunTest(const FString& Parameters)
{
	UAshenPlausibleDestructivenessEvaluator* Eval = NewObject<UAshenPlausibleDestructivenessEvaluator>();
	if (!TestNotNull(TEXT("PlausibleDestructivenessEvaluator must be constructable"), Eval)) return false;

	const FString Whisper = Eval->SelectMostDestructivePlausibleWhisper(FName(TEXT("Memory.GarrettCrossguard")), 0.9f);
	TestTrue(TEXT("Selected Whisper must not be empty"), !Whisper.IsEmpty());

	return true;
}

// =============================================================================
//  Test 3: Entropy Of Meaning Subsystem — Accrue Entropy
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEntropyOfMeaningSubsystemTest,
	"AshenOath.EntropyOfMeaning.Subsystem.AccrueEntropy",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenEntropyOfMeaningSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenEntropyOfMeaningSubsystem* EntropySys = NewObject<UAshenEntropyOfMeaningSubsystem>();
	if (!TestNotNull(TEXT("EntropyOfMeaningSubsystem must be constructable"), EntropySys)) return false;

	EntropySys->AccrueNarrativeEntropy(35.0f);
	TestEqual(TEXT("ActiveNarrativeEntropy must equal 35.0"), EntropySys->ActiveNarrativeEntropy, 35.0f);

	return true;
}
