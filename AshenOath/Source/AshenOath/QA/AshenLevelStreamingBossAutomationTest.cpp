// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 162: Ashen Level Streaming & Boss State Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenLevelStreamingSubsystem.h"
#include "AshenUserWidget_BossHealthBar.h"

// =============================================================================
//  Test 1: Level Streaming Subsystem — Zone Registration
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenLevelStreamingZoneRegistrationTest,
	"AshenOath.LevelStreaming.ZoneRegistration",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenLevelStreamingZoneRegistrationTest::RunTest(const FString& Parameters)
{
	// Verify subsystem exists at runtime
	TestTrue(
		TEXT("UAshenLevelStreamingSubsystem class must be valid"),
		UAshenLevelStreamingSubsystem::StaticClass() != nullptr
	);

	// Verify RequestZoneStream is a valid UFUNCTION
	UFunction* RequestFn = UAshenLevelStreamingSubsystem::StaticClass()->FindFunctionByName(
		FName(TEXT("RequestZoneStream"))
	);
	TestNotNull(TEXT("RequestZoneStream must be a registered UFUNCTION"), RequestFn);

	// Verify UnloadZoneStream is a valid UFUNCTION
	UFunction* UnloadFn = UAshenLevelStreamingSubsystem::StaticClass()->FindFunctionByName(
		FName(TEXT("UnloadZoneStream"))
	);
	TestNotNull(TEXT("UnloadZoneStream must be a registered UFUNCTION"), UnloadFn);

	return true;
}

// =============================================================================
//  Test 2: Boss Health Bar Widget — Health Clamping
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossHealthBarClampTest,
	"AshenOath.UI.BossHealthBar.HealthClamp",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossHealthBarClampTest::RunTest(const FString& Parameters)
{
	// Construct a transient widget to validate logic
	UAshenUserWidget_BossHealthBar* Widget = NewObject<UAshenUserWidget_BossHealthBar>();
	if (!TestNotNull(TEXT("BossHealthBar widget must be constructable"), Widget))
	{
		return false;
	}

	// Verify health clamps to [0.0, 1.0] on extreme values
	Widget->UpdateBossHealth(9999.0f, 100.0f, 1);
	TestEqual(TEXT("Health must clamp to 1.0 when above max"), Widget->CurrentHealthPercent, 1.0f);

	Widget->UpdateBossHealth(-500.0f, 100.0f, 1);
	TestEqual(TEXT("Health must clamp to 0.0 when below zero"), Widget->CurrentHealthPercent, 0.0f);

	// Verify normal health percent
	Widget->UpdateBossHealth(50.0f, 100.0f, 1);
	TestEqual(TEXT("Health must compute to 0.5 at half-health"), Widget->CurrentHealthPercent, 0.5f);

	return true;
}

// =============================================================================
//  Test 3: Boss Health Bar Widget — Phase Transition
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossPhaseTransitionTest,
	"AshenOath.UI.BossHealthBar.PhaseTransition",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossPhaseTransitionTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_BossHealthBar* Widget = NewObject<UAshenUserWidget_BossHealthBar>();
	if (!TestNotNull(TEXT("BossHealthBar widget must be constructable"), Widget))
	{
		return false;
	}

	// Trigger phase transition and validate phase state update
	Widget->ShowPhaseTransitionBanner(2);
	TestEqual(TEXT("Boss phase must update to 2 after transition banner"), Widget->CurrentBossPhase, 2);

	Widget->ShowPhaseTransitionBanner(3);
	TestEqual(TEXT("Boss phase must update to 3 after second transition"), Widget->CurrentBossPhase, 3);

	return true;
}

// =============================================================================
//  Test 4: Boss Health Bar Widget — Boss Name Display
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossNameDisplayTest,
	"AshenOath.UI.BossHealthBar.BossName",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossNameDisplayTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_BossHealthBar* Widget = NewObject<UAshenUserWidget_BossHealthBar>();
	if (!TestNotNull(TEXT("BossHealthBar widget must be constructable"), Widget))
	{
		return false;
	}

	const FText BossNameText = FText::FromString(TEXT("The Shroud Knight"));
	Widget->DisplayBossName(BossNameText);

	TestTrue(
		TEXT("Boss name must be 'The Shroud Knight' after DisplayBossName call"),
		Widget->CurrentBossName.EqualTo(BossNameText)
	);

	return true;
}

// =============================================================================
//  Test 5: Stamina Exhaustion Component — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenStaminaExhaustionReflectionTest,
	"AshenOath.Stamina.ExhaustionComponent.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenStaminaExhaustionReflectionTest::RunTest(const FString& Parameters)
{
	UClass* ExhaustionClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.AshenStaminaExhaustionComponent"));

	TestNotNull(TEXT("UAshenStaminaExhaustionComponent must be registered in the asset registry"), ExhaustionClass);

	if (ExhaustionClass)
	{
		UFunction* CheckFn = ExhaustionClass->FindFunctionByName(FName(TEXT("CheckExhaustionState")));
		TestNotNull(TEXT("CheckExhaustionState must be a registered UFUNCTION"), CheckFn);

		UFunction* IsExhaustedFn = ExhaustionClass->FindFunctionByName(FName(TEXT("IsExhausted")));
		TestNotNull(TEXT("IsExhausted must be a registered UFUNCTION"), IsExhaustedFn);
	}

	return true;
}
