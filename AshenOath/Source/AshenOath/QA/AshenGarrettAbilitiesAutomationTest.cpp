// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 705: Ashen Garrett Abilities & Stealth Mechanics Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenGarrettShadowStepStealthComponent.h"
#include "AshenGarrettPoisonBladeExecutionAbility.h"
#include "AshenGarrettFlashPowderBlindEvaluator.h"

// =============================================================================
//  Test 1: Garrett Shadow Step Stealth Component — Execute Step
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGarrettShadowStepStealthComponentTest,
	"AshenOath.GarrettShadowStep.Component.ExecuteStep",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGarrettShadowStepStealthComponentTest::RunTest(const FString& Parameters)
{
	UAshenGarrettShadowStepStealthComponent* StealthComp = NewObject<UAshenGarrettShadowStepStealthComponent>();
	if (!TestNotNull(TEXT("GarrettShadowStepStealthComponent must be constructable"), StealthComp)) return false;

	StealthComp->ExecuteShadowStep(FVector(100.0f, 200.0f, 0.0f));
	TestTrue(TEXT("bIsStealthed must equal true"), StealthComp->bIsStealthed);

	return true;
}

// =============================================================================
//  Test 2: Garrett Poison Blade Execution Ability — Execute Ability
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGarrettPoisonBladeExecutionAbilityTest,
	"AshenOath.GarrettAbilities.Ability.PoisonBlade",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGarrettPoisonBladeExecutionAbilityTest::RunTest(const FString& Parameters)
{
	UAshenGarrettPoisonBladeExecutionAbility* Ability = NewObject<UAshenGarrettPoisonBladeExecutionAbility>();
	if (!TestNotNull(TEXT("GarrettPoisonBladeExecutionAbility must be constructable"), Ability)) return false;

	Ability->ExecutePoisonBlade(nullptr, 40.0f); // Null target safety test
	return true;
}

// =============================================================================
//  Test 3: Garrett Flash Powder Blind Evaluator — Evaluate Impact
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGarrettFlashPowderBlindEvaluatorTest,
	"AshenOath.GarrettFlashPowder.Evaluator.EvaluateImpact",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGarrettFlashPowderBlindEvaluatorTest::RunTest(const FString& Parameters)
{
	UAshenGarrettFlashPowderBlindEvaluator* Eval = NewObject<UAshenGarrettFlashPowderBlindEvaluator>();
	if (!TestNotNull(TEXT("GarrettFlashPowderBlindEvaluator must be constructable"), Eval)) return false;

	const float Duration = Eval->EvaluateFlashPowderBlindImpact(0.0f, 10.0f); // 0 distance = 5.0s max duration
	TestEqual(TEXT("Blind duration at 0 distance must equal 5.0 seconds"), Duration, 5.0f);

	return true;
}
