// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 265: Ashen Dungeon Pressure Plate & Insanity Hallucination Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDungeonPressurePlateComponent.h"
#include "GA_GarrettAssassinationDash.h"
#include "AshenSanityInsanityHallucinationSubsystem.h"
#include "AshenUserWidget_PressurePlateStatus.h"

// =============================================================================
//  Test 1: Pressure Plate Component — Depress & Release State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPressurePlateStateTest,
	"AshenOath.Dungeon.PressurePlate.DepressAndRelease",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPressurePlateStateTest::RunTest(const FString& Parameters)
{
	UAshenDungeonPressurePlateComponent* Plate = NewObject<UAshenDungeonPressurePlateComponent>();
	if (!TestNotNull(TEXT("DungeonPressurePlateComponent must be constructable"), Plate)) return false;

	TestFalse(TEXT("Plate must initially not be depressed"), Plate->IsDepressed());
	Plate->OnActorSteppedOn(nullptr);
	TestTrue(TEXT("Plate must be depressed after OnActorSteppedOn"), Plate->IsDepressed());

	Plate->OnActorSteppedOff(nullptr);
	TestFalse(TEXT("Plate must not be depressed after OnActorSteppedOff"), Plate->IsDepressed());

	return true;
}

// =============================================================================
//  Test 2: Garrett Assassination Dash — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAssassinationDashClassTest,
	"AshenOath.GAS.GarrettAssassinationDash.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAssassinationDashClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_GarrettAssassinationDash"));
	TestNotNull(TEXT("UGA_GarrettAssassinationDash must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Insanity Hallucination Subsystem — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenInsanityHallucinationReflectionTest,
	"AshenOath.Sanity.InsanityHallucination.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenInsanityHallucinationReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenSanityInsanityHallucinationSubsystem class must be valid"),
		UAshenSanityInsanityHallucinationSubsystem::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Pressure Plate Status Widget — Update Puzzle Status
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPressurePlateStatusWidgetTest,
	"AshenOath.UI.PressurePlateStatusWidget.UpdateStatus",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPressurePlateStatusWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_PressurePlateStatus* Widget = NewObject<UAshenUserWidget_PressurePlateStatus>();
	if (!TestNotNull(TEXT("PressurePlateStatus widget must be constructable"), Widget)) return false;

	Widget->UpdatePlatePuzzleStatus(3, 3, true);
	TestEqual(TEXT("DepressedPlateCount must be 3"), Widget->DepressedPlateCount, 3);
	TestTrue(TEXT("bPuzzleComplete must be true"), Widget->bPuzzleComplete);

	return true;
}

// =============================================================================
//  Test 5: Pressure Plate Component — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPressurePlateReflectionTest,
	"AshenOath.Dungeon.PressurePlate.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPressurePlateReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenDungeonPressurePlateComponent class must be valid"),
		UAshenDungeonPressurePlateComponent::StaticClass() != nullptr);
	return true;
}
