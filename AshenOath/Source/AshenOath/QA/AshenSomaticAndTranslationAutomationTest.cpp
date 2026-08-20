// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 610: Ashen Somatic Presentation, UI Rules & Translation Engine Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenSomaticPresentationController.h"
#include "AshenInterfaceWorldAvailabilitySubsystem.h"
#include "AshenPsychologicalTranslationEngine.h"

// =============================================================================
//  Test 1: Somatic Presentation Controller — Evaluate
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSomaticPresentationControllerTest,
	"AshenOath.SomaticUI.Controller.Evaluate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSomaticPresentationControllerTest::RunTest(const FString& Parameters)
{
	UAshenSomaticPresentationController* Controller = NewObject<UAshenSomaticPresentationController>();
	if (!TestNotNull(TEXT("SomaticPresentationController must be constructable"), Controller)) return false;

	Controller->EvaluateSomaticPresentation(0.8f, 0.5f, 0.4f);
	TestEqual(TEXT("CalculatedHandwritingWobble must equal 0.72"), Controller->CalculatedHandwritingWobble, 0.72f);

	return true;
}

// =============================================================================
//  Test 2: Interface World Availability Subsystem — Rules Enforcer
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenInterfaceWorldAvailabilitySubsystemTest,
	"AshenOath.UIRules.Subsystem.CanOpenUIScreen",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenInterfaceWorldAvailabilitySubsystemTest::RunTest(const FString& Parameters)
{
	UAshenInterfaceWorldAvailabilitySubsystem* RulesSys = NewObject<UAshenInterfaceWorldAvailabilitySubsystem>();
	if (!TestNotNull(TEXT("InterfaceWorldAvailabilitySubsystem must be constructable"), RulesSys)) return false;

	TestTrue(TEXT("Camp screen must be available near campfire"), RulesSys->CanOpenUIScreen(EAshenDiegeticUIScreen::Camp, true, false));
	TestFalse(TEXT("Camp screen must NOT be available away from campfire"), RulesSys->CanOpenUIScreen(EAshenDiegeticUIScreen::Camp, false, false));

	return true;
}

// =============================================================================
//  Test 3: Psychological Translation Engine — Variable Translation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPsychologicalTranslationEngineTest,
	"AshenOath.PsychologicalTranslation.Engine.TranslateVariables",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPsychologicalTranslationEngineTest::RunTest(const FString& Parameters)
{
	UAshenPsychologicalTranslationEngine* TransEngine = NewObject<UAshenPsychologicalTranslationEngine>();
	if (!TestNotNull(TEXT("PsychologicalTranslationEngine must be constructable"), TransEngine)) return false;

	TransEngine->TranslateEngineVariables(0.85f, 0.70f, 0.90f);
	TestEqual(TEXT("CurrentMindStateText must be 'Mind is Fracturing'"), TransEngine->CurrentMindStateText, FString(TEXT("Mind is Fracturing")));

	return true;
}
