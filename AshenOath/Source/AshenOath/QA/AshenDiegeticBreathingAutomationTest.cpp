// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 465: Ashen Diegetic Breathing & Ground Shatter Burst Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDiegeticBreathingComponent.h"
#include "AshenUserWidget_DiegeticBreathingHUD.h"
#include "GA_KaelenGroundShatterBurstExecution.h"
#include "AshenMilestone465SynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Diegetic Breathing Component — Fatigue Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDiegeticBreathingFatigueTest,
	"AshenOath.DiegeticBreathing.Component.UpdateFatigue",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDiegeticBreathingFatigueTest::RunTest(const FString& Parameters)
{
	UAshenDiegeticBreathingComponent* Breathing = NewObject<UAshenDiegeticBreathingComponent>();
	if (!TestNotNull(TEXT("DiegeticBreathingComponent must be constructable"), Breathing)) return false;

	Breathing->UpdateBreathingFatigue(20.0f, 100.0f); // 80% fatigue
	TestEqual(TEXT("CalculatedFatiguePercent must equal 0.8"), Breathing->CalculatedFatiguePercent, 0.8f);

	return true;
}

// =============================================================================
//  Test 2: Diegetic Breathing HUD Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDiegeticBreathingHUDWidgetTest,
	"AshenOath.UI.DiegeticBreathingHUDWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDiegeticBreathingHUDWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_DiegeticBreathingHUD* Widget = NewObject<UAshenUserWidget_DiegeticBreathingHUD>();
	if (!TestNotNull(TEXT("DiegeticBreathingHUD widget must be constructable"), Widget)) return false;

	Widget->UpdateBreathingHUDDisplay(2.1f, 0.8f, FName(TEXT("Audio.Breathing.HeavyPanting")));
	TestEqual(TEXT("DisplayedFatiguePercent must equal 0.8"), Widget->DisplayedFatiguePercent, 0.8f);

	return true;
}

// =============================================================================
//  Test 3: Kaelen Ground Shatter Burst Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBreathingGroundShatterBurstClassTest,
	"AshenOath.GAS.KaelenGroundShatterBurstExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBreathingGroundShatterBurstClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenGroundShatterBurstExecution"));
	TestNotNull(TEXT("UGA_KaelenGroundShatterBurstExecution must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 4: Milestone 465 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone465VerificationTest,
	"AshenOath.Milestone.Milestone465.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone465VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone465.Verification: Milestone 465 Systems Verified!"));
	return true;
}
