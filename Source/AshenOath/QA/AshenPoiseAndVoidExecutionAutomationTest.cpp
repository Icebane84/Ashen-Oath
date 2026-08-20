// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 455: Ashen Poise Break & Void Shatter Execution Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GA_KaelenUnchainedVoidShatterExecution.h"
#include "AshenEnemyPoiseBreakComponent.h"
#include "AshenUserWidget_PoiseBreakHUD.h"

// =============================================================================
//  Test 1: Kaelen Unchained Void Shatter Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVoidShatterExecutionClassTest,
	"AshenOath.GAS.KaelenUnchainedVoidShatterExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVoidShatterExecutionClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenUnchainedVoidShatterExecution"));
	TestNotNull(TEXT("UGA_KaelenUnchainedVoidShatterExecution must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 2: Enemy Poise Break Component — Poise Depletion & Break Trigger
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPoiseBreakComponentTest,
	"AshenOath.PoiseBreak.Component.ApplyDamageAndBreak",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPoiseBreakComponentTest::RunTest(const FString& Parameters)
{
	UAshenEnemyPoiseBreakComponent* PoiseComp = NewObject<UAshenEnemyPoiseBreakComponent>();
	if (!TestNotNull(TEXT("EnemyPoiseBreakComponent must be constructable"), PoiseComp)) return false;

	PoiseComp->ApplyPoiseDamage(120.0f);
	TestTrue(TEXT("bIsPoiseBroken must equal true after 120 poise damage"), PoiseComp->IsPoiseBroken());

	return true;
}

// =============================================================================
//  Test 3: Poise Break HUD Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPoiseBreakHUDWidgetTest,
	"AshenOath.UI.PoiseBreakHUDWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPoiseBreakHUDWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_PoiseBreakHUD* Widget = NewObject<UAshenUserWidget_PoiseBreakHUD>();
	if (!TestNotNull(TEXT("PoiseBreakHUD widget must be constructable"), Widget)) return false;

	Widget->UpdatePoiseHUDDisplay(0.0f, 100.0f, true);
	TestTrue(TEXT("bDisplayedIsBroken must equal true"), Widget->bDisplayedIsBroken);

	return true;
}
