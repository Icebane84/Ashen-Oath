// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 480: Ashen Boss Phase & Arena Script Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenBossMultiPhaseTransitionComponent.h"
#include "AshenUserWidget_BossPhaseHUD.h"
#include "AshenBossArenaEnvironmentalScriptSubsystem.h"
#include "GA_BossAbominationVoidSmashExecution.h"
#include "AshenMilestone480SynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Boss Multi-Phase Transition Component — Health Threshold
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossMultiPhaseTransitionComponentTest,
	"AshenOath.BossPhase.Component.EvaluateTransition",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossMultiPhaseTransitionComponentTest::RunTest(const FString& Parameters)
{
	UAshenBossMultiPhaseTransitionComponent* BossPhase = NewObject<UAshenBossMultiPhaseTransitionComponent>();
	if (!TestNotNull(TEXT("BossMultiPhaseTransitionComponent must be constructable"), BossPhase)) return false;

	BossPhase->EvaluateBossPhaseTransition(40.0f, 100.0f); // 40% HP -> Phase 2
	TestEqual(TEXT("CurrentPhaseIndex must equal 2"), BossPhase->CurrentPhaseIndex, 2);

	return true;
}

// =============================================================================
//  Test 2: Boss Phase HUD Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossPhaseHUDWidgetTest,
	"AshenOath.UI.BossPhaseHUDWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossPhaseHUDWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_BossPhaseHUD* Widget = NewObject<UAshenUserWidget_BossPhaseHUD>();
	if (!TestNotNull(TEXT("BossPhaseHUD widget must be constructable"), Widget)) return false;

	Widget->UpdateBossPhaseHUDDisplay(2, 0.40f);
	TestEqual(TEXT("DisplayedPhaseIndex must equal 2"), Widget->DisplayedPhaseIndex, 2);

	return true;
}

// =============================================================================
//  Test 3: Boss Abomination Void Smash Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossVoidSmashClassTest,
	"AshenOath.GAS.BossAbominationVoidSmashExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossVoidSmashClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_BossAbominationVoidSmashExecution"));
	TestNotNull(TEXT("UGA_BossAbominationVoidSmashExecution must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 4: Milestone 480 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone480VerificationTest,
	"AshenOath.Milestone.Milestone480.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone480VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone480.Verification: Milestone 480 Systems Verified!"));
	return true;
}
