// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 275: Ashen Dungeon Keycard & Poison Smoke Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDungeonLootKeycardComponent.h"
#include "GA_GarrettPoisonSmokeGrid.h"
#include "AshenSanityHallucinationVFXComponent.h"
#include "AshenUserWidget_DungeonKeycardNotification.h"

// =============================================================================
//  Test 1: Keycard Component — Collection State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenKeycardCollectionTest,
	"AshenOath.Dungeon.Keycard.CollectionState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenKeycardCollectionTest::RunTest(const FString& Parameters)
{
	UAshenDungeonLootKeycardComponent* Key = NewObject<UAshenDungeonLootKeycardComponent>();
	if (!TestNotNull(TEXT("DungeonLootKeycardComponent must be constructable"), Key)) return false;

	TestFalse(TEXT("Keycard must initially not be collected"), Key->IsCollected());
	Key->CollectKeycard(nullptr);
	TestTrue(TEXT("Keycard must be collected after CollectKeycard"), Key->IsCollected());

	return true;
}

// =============================================================================
//  Test 2: Garrett Poison Smoke Grid — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPoisonSmokeGridClassTest,
	"AshenOath.GAS.GarrettPoisonSmoke.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPoisonSmokeGridClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_GarrettPoisonSmokeGrid"));
	TestNotNull(TEXT("UGA_GarrettPoisonSmokeGrid must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Hallucination VFX Component — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHallucinationVFXReflectionTest,
	"AshenOath.VFX.SanityHallucination.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenHallucinationVFXReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenSanityHallucinationVFXComponent class must be valid"),
		UAshenSanityHallucinationVFXComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Keycard Notification Widget — Display & Dismiss
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenKeycardNotificationWidgetTest,
	"AshenOath.UI.KeycardNotificationWidget.DisplayAndDismiss",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenKeycardNotificationWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_DungeonKeycardNotification* Widget = NewObject<UAshenUserWidget_DungeonKeycardNotification>();
	if (!TestNotNull(TEXT("KeycardNotification widget must be constructable"), Widget)) return false;

	const FName KeyID(TEXT("RuneKey_01"));
	const FText KeyName = FText::FromString(TEXT("Rune of Greywatch"));

	Widget->DisplayKeycardAcquiredNotification(KeyID, KeyName);
	TestTrue(TEXT("bNotificationActive must be true after display"), Widget->bNotificationActive);

	Widget->DismissNotification();
	TestFalse(TEXT("bNotificationActive must be false after dismiss"), Widget->bNotificationActive);

	return true;
}

// =============================================================================
//  Test 5: Keycard Component — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenKeycardReflectionTest,
	"AshenOath.Dungeon.Keycard.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenKeycardReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenDungeonLootKeycardComponent class must be valid"),
		UAshenDungeonLootKeycardComponent::StaticClass() != nullptr);
	return true;
}
