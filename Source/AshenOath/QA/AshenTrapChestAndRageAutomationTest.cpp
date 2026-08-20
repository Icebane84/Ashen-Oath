// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 295: Ashen Trap Chest & Kaelen Rage Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDungeonLootTrapChestComponent.h"
#include "GA_KaelenUnchainedRageMode.h"
#include "AshenAudioInsanityVoiceSubsystem.h"
#include "AshenUserWidget_TrapChestWarning.h"

// =============================================================================
//  Test 1: Trap Chest Component — Sprung State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTrapChestSprungTest,
	"AshenOath.Dungeon.TrapChest.SprungState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTrapChestSprungTest::RunTest(const FString& Parameters)
{
	UAshenDungeonLootTrapChestComponent* Trap = NewObject<UAshenDungeonLootTrapChestComponent>();
	if (!TestNotNull(TEXT("DungeonLootTrapChestComponent must be constructable"), Trap)) return false;

	TestFalse(TEXT("Trap must initially not be sprung"), Trap->IsSprung());
	Trap->TriggerChest(nullptr);
	TestTrue(TEXT("Trap must be sprung after TriggerChest"), Trap->IsSprung());

	return true;
}

// =============================================================================
//  Test 2: Kaelen Unchained Rage Mode — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenUnchainedRageClassTest,
	"AshenOath.GAS.KaelenUnchainedRage.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenUnchainedRageClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenUnchainedRageMode"));
	TestNotNull(TEXT("UGA_KaelenUnchainedRageMode must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Audio Insanity Voice Subsystem — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenInsanityVoiceReflectionTest,
	"AshenOath.Audio.InsanityVoiceSubsystem.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenInsanityVoiceReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenAudioInsanityVoiceSubsystem class must be valid"),
		UAshenAudioInsanityVoiceSubsystem::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Trap Chest Warning Widget — Display & Dismiss
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTrapChestWarningWidgetTest,
	"AshenOath.UI.TrapChestWarningWidget.DisplayAndDismiss",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTrapChestWarningWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_TrapChestWarning* Warning = NewObject<UAshenUserWidget_TrapChestWarning>();
	if (!TestNotNull(TEXT("TrapChestWarning widget must be constructable"), Warning)) return false;

	const FText WarningText = FText::FromString(TEXT("Poison Trap Triggered!"));
	Warning->DisplayTrapWarning(WarningText);
	TestTrue(TEXT("bWarningActive must be true after display"), Warning->bWarningActive);

	Warning->DismissWarning();
	TestFalse(TEXT("bWarningActive must be false after dismiss"), Warning->bWarningActive);

	return true;
}

// =============================================================================
//  Test 5: Trap Chest Component — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTrapChestReflectionTest,
	"AshenOath.Dungeon.TrapChest.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTrapChestReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenDungeonLootTrapChestComponent class must be valid"),
		UAshenDungeonLootTrapChestComponent::StaticClass() != nullptr);
	return true;
}
