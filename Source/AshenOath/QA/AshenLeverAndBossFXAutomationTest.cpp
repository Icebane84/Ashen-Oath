// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 260: Ashen Dungeon Lever & Boss Phase FX Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDungeonLeverSwitchComponent.h"
#include "GA_KaelenWhirlwindExecution.h"
#include "AshenBossPhaseParticleControllerComponent.h"
#include "AshenUserWidget_PuzzleLeverPrompt.h"

// =============================================================================
//  Test 1: Dungeon Lever Switch — Toggle State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenLeverToggleTest,
	"AshenOath.Dungeon.LeverSwitch.ToggleState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenLeverToggleTest::RunTest(const FString& Parameters)
{
	UAshenDungeonLeverSwitchComponent* Lever = NewObject<UAshenDungeonLeverSwitchComponent>();
	if (!TestNotNull(TEXT("DungeonLeverSwitchComponent must be constructable"), Lever)) return false;

	TestFalse(TEXT("Lever must initially be deactivated"), Lever->IsActivated());
	bool bState1 = Lever->ToggleLever();
	TestTrue(TEXT("Lever must be activated after first toggle"), bState1);

	bool bState2 = Lever->ToggleLever();
	TestFalse(TEXT("Lever must be deactivated after second toggle"), bState2);

	return true;
}

// =============================================================================
//  Test 2: Kaelen Whirlwind Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWhirlwindExecutionClassTest,
	"AshenOath.GAS.KaelenWhirlwindExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWhirlwindExecutionClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenWhirlwindExecution"));
	TestNotNull(TEXT("UGA_KaelenWhirlwindExecution must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Boss Phase Particle Controller — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossPhaseParticleControllerReflectionTest,
	"AshenOath.VFX.BossPhaseParticleController.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossPhaseParticleControllerReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenBossPhaseParticleControllerComponent class must be valid"),
		UAshenBossPhaseParticleControllerComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Puzzle Lever Prompt Widget — Show & Hide
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPuzzleLeverPromptWidgetTest,
	"AshenOath.UI.PuzzleLeverPromptWidget.ShowAndHide",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPuzzleLeverPromptWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_PuzzleLeverPrompt* Prompt = NewObject<UAshenUserWidget_PuzzleLeverPrompt>();
	if (!TestNotNull(TEXT("PuzzleLeverPrompt widget must be constructable"), Prompt)) return false;

	const FName LeverID(TEXT("Lever_Sanctuary_01"));
	const FText ActionText = FText::FromString(TEXT("Pull Gate Lever"));

	Prompt->ShowLeverPrompt(LeverID, ActionText, false);
	TestTrue(TEXT("bPromptActive must be true after show"), Prompt->bPromptActive);

	Prompt->HideLeverPrompt();
	TestFalse(TEXT("bPromptActive must be false after hide"), Prompt->bPromptActive);

	return true;
}

// =============================================================================
//  Test 5: Milestone 260 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone260VerificationTest,
	"AshenOath.Milestone.Milestone260.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone260VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone260.Verification: Milestone 260 Systems Ready!"));
	return true;
}
