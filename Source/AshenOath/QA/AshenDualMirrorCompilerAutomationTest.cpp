// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 630: Ashen Dual Mirror Compiler Automation Tests (UMB-INT-001)

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenUserWidget_ContestedInterpretation.h"
#include "AshenInterpretiveLensSelectorComponent.h"
#include "AshenMechanicalHonestyRuleEnforcer.h"

// =============================================================================
//  Test 1: Contested Interpretation Widget — Display
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenContestedInterpretationWidgetTest,
	"AshenOath.UI.ContestedInterpretationWidget.Display",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenContestedInterpretationWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_ContestedInterpretation* Widget = NewObject<UAshenUserWidget_ContestedInterpretation>();
	if (!TestNotNull(TEXT("ContestedInterpretation widget must be constructable"), Widget)) return false;

	Widget->DisplayContestedInterpretation(
		FName(TEXT("Memory.SunderingOath")),
		FText::FromString(TEXT("Garrett offered Kaelen his blade.")),
		FText::FromString(TEXT("Garrett intended to disarm Kaelen.")),
		true
	);
	TestTrue(TEXT("bIsActivePassFragmenting must be true"), Widget->bIsActivePassFragmenting);

	return true;
}

// =============================================================================
//  Test 2: Interpretive Lens Selector Component — Lens Selection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenInterpretiveLensSelectorComponentTest,
	"AshenOath.InterpretiveLens.Component.SelectLens",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenInterpretiveLensSelectorComponentTest::RunTest(const FString& Parameters)
{
	UAshenInterpretiveLensSelectorComponent* Selector = NewObject<UAshenInterpretiveLensSelectorComponent>();
	if (!TestNotNull(TEXT("InterpretiveLensSelectorComponent must be constructable"), Selector)) return false;

	Selector->SelectLensForMemory(FName(TEXT("Memory.BlackwoodBridge")), EAshenInterpretiveLens::Accountability);
	TestEqual(TEXT("CurrentActiveLens must equal Accountability"), Selector->CurrentActiveLens, EAshenInterpretiveLens::Accountability);

	return true;
}

// =============================================================================
//  Test 3: Mechanical Honesty Rule Enforcer — Authenticity Audit
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMechanicalHonestyRuleEnforcerTest,
	"AshenOath.MechanicalHonesty.Enforcer.ValidateTruth",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMechanicalHonestyRuleEnforcerTest::RunTest(const FString& Parameters)
{
	UAshenMechanicalHonestyRuleEnforcer* Enforcer = NewObject<UAshenMechanicalHonestyRuleEnforcer>();
	if (!TestNotNull(TEXT("MechanicalHonestyRuleEnforcer must be constructable"), Enforcer)) return false;

	TestTrue(TEXT("Raw stamina 100.0 must match presented stamina 100.0"), Enforcer->ValidateMechanicalTruth(FName(TEXT("System.StaminaCost")), 100.0f, 100.0f));

	return true;
}
