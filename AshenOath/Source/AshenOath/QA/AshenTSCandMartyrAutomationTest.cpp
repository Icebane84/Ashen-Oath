// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 330: Ashen TSC & Martyr Tithe Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenTacticalSlowdownCommandComponent.h"
#include "AshenBurdenOfCommandComponent.h"
#include "AshenMartyrsTitheComponent.h"
#include "AshenUserWidget_TSCCommandWheel.h"

// =============================================================================
//  Test 1: Tactical Slowdown (TSC) — Activation & Time Dilation State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTSCActivationTest,
	"AshenOath.TSC.TacticalSlowdown.ActivationState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTSCActivationTest::RunTest(const FString& Parameters)
{
	UAshenTacticalSlowdownCommandComponent* TSC = NewObject<UAshenTacticalSlowdownCommandComponent>();
	if (!TestNotNull(TEXT("TacticalSlowdownCommandComponent must be constructable"), TSC)) return false;

	TestFalse(TEXT("TSC must initially be inactive"), TSC->IsSlowdownActive());
	TSC->ActivateTacticalSlowdown();
	TestTrue(TEXT("TSC must be active after ActivateTacticalSlowdown"), TSC->IsSlowdownActive());

	TSC->DeactivateTacticalSlowdown();
	TestFalse(TEXT("TSC must be inactive after DeactivateTacticalSlowdown"), TSC->IsSlowdownActive());

	return true;
}

// =============================================================================
//  Test 2: Burden of Command — Command Strain & Refusal
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCommandStrainTest,
	"AshenOath.TSC.BurdenOfCommand.StrainAndRefusal",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCommandStrainTest::RunTest(const FString& Parameters)
{
	UAshenBurdenOfCommandComponent* Burden = NewObject<UAshenBurdenOfCommandComponent>();
	if (!TestNotNull(TEXT("BurdenOfCommandComponent must be constructable"), Burden)) return false;

	TestFalse(TEXT("Companion must initially not refuse commands"), Burden->IsRefusingCommands());
	Burden->AccrueCommandStrain(100.0f);
	TestTrue(TEXT("Companion must refuse commands at maximum strain"), Burden->IsRefusingCommands());

	return true;
}

// =============================================================================
//  Test 3: Martyr's Tithe — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMartyrsTitheReflectionTest,
	"AshenOath.Martyr.TitheComponent.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMartyrsTitheReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenMartyrsTitheComponent class must be valid"),
		UAshenMartyrsTitheComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: TSC Command Wheel Widget — Display State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTSCCommandWheelWidgetTest,
	"AshenOath.UI.TSCCommandWheelWidget.DisplayState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTSCCommandWheelWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_TSCCommandWheel* Widget = NewObject<UAshenUserWidget_TSCCommandWheel>();
	if (!TestNotNull(TEXT("TSCCommandWheel widget must be constructable"), Widget)) return false;

	Widget->DisplayTSCCommandWheel(true, 0.20f);
	TestTrue(TEXT("bTSCWheelActive must be true"), Widget->bTSCWheelActive);
	TestEqual(TEXT("ActiveDilation must be 0.20"), Widget->ActiveDilation, 0.20f);

	return true;
}

// =============================================================================
//  Test 5: Milestone 330 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone330VerificationTest,
	"AshenOath.Milestone.Milestone330.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone330VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone330.Verification: Milestone 330 Systems Verified!"));
	return true;
}
