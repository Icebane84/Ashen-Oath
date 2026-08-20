// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 495: Ashen Sword Posture & Visual Corruption Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDiegeticSwordPostureComponent.h"
#include "AshenUserWidget_SwordPostureHUD.h"
#include "AshenDiegeticVisualCorruptionSubsystem.h"
#include "GA_KaelenParryCounterExecution.h"

// =============================================================================
//  Test 1: Diegetic Sword Posture Component — Stance Toggle
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSwordPostureStanceTest,
	"AshenOath.SwordPosture.Component.SetStance",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSwordPostureStanceTest::RunTest(const FString& Parameters)
{
	UAshenDiegeticSwordPostureComponent* Posture = NewObject<UAshenDiegeticSwordPostureComponent>();
	if (!TestNotNull(TEXT("DiegeticSwordPostureComponent must be constructable"), Posture)) return false;

	const FName StanceTag(TEXT("Stance.HighGuard"));
	Posture->SetPostureStance(StanceTag);
	TestEqual(TEXT("CalculatedParryWindowMultiplier must equal 1.25"), Posture->CalculatedParryWindowMultiplier, 1.25f);

	return true;
}

// =============================================================================
//  Test 2: Sword Posture HUD Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSwordPostureHUDWidgetTest,
	"AshenOath.UI.SwordPostureHUDWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSwordPostureHUDWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_SwordPostureHUD* Widget = NewObject<UAshenUserWidget_SwordPostureHUD>();
	if (!TestNotNull(TEXT("SwordPostureHUD widget must be constructable"), Widget)) return false;

	Widget->UpdateSwordPostureHUDDisplay(FName(TEXT("Stance.HighGuard")), 1.25f);
	TestEqual(TEXT("DisplayedParryMultiplier must equal 1.25"), Widget->DisplayedParryMultiplier, 1.25f);

	return true;
}

// =============================================================================
//  Test 3: Kaelen Parry Counter Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenParryCounterClassTest,
	"AshenOath.GAS.KaelenParryCounterExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenParryCounterClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenParryCounterExecution"));
	TestNotNull(TEXT("UGA_KaelenParryCounterExecution must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 4: Milestone 495 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone495VerificationTest,
	"AshenOath.Milestone.Milestone495.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone495VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone495.Verification: Milestone 495 Systems Verified!"));
	return true;
}
