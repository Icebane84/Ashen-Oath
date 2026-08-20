// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 375: Ashen Focus Mode & Psychic Echoes Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenFocusModeInvestigationComponent.h"
#include "GA_KaelenResonanceShiftAttack.h"
#include "AshenPsychicEchoesLocationSubsystem.h"

// =============================================================================
//  Test 1: Focus Mode Component — Toggle Active
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFocusModeToggleTest,
	"AshenOath.FocusMode.InvestigationComponent.ToggleActive",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFocusModeToggleTest::RunTest(const FString& Parameters)
{
	UAshenFocusModeInvestigationComponent* Focus = NewObject<UAshenFocusModeInvestigationComponent>();
	if (!TestNotNull(TEXT("FocusModeInvestigationComponent must be constructable"), Focus)) return false;

	TestFalse(TEXT("Initially FocusMode must be inactive"), Focus->IsFocusModeActive());
	Focus->ToggleFocusMode(true);
	TestTrue(TEXT("FocusMode must be active after ToggleFocusMode(true)"), Focus->IsFocusModeActive());

	return true;
}

// =============================================================================
//  Test 2: Kaelen Resonance Shift Attack — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenResonanceShiftAttackClassTest,
	"AshenOath.GAS.KaelenResonanceShiftAttack.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenResonanceShiftAttackClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenResonanceShiftAttack"));
	TestNotNull(TEXT("UGA_KaelenResonanceShiftAttack must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Psychic Echoes Location Subsystem — Imprint & Query
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPsychicEchoesSubsystemTest,
	"AshenOath.PsychicEchoes.LocationSubsystem.ImprintAndQuery",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPsychicEchoesSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenPsychicEchoesLocationSubsystem* Echoes = NewObject<UAshenPsychicEchoesLocationSubsystem>();
	if (!TestNotNull(TEXT("PsychicEchoesLocationSubsystem must be constructable"), Echoes)) return false;

	const FName LocationID(TEXT("Location_RuinsOfAethelgard"));
	Echoes->ImprintPsychicEchoAtLocation(LocationID, 85.0f);
	TestEqual(TEXT("Echo intensity must equal 85.0"), Echoes->GetLocationEchoIntensity(LocationID), 85.0f);

	return true;
}
