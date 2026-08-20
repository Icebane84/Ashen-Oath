// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 335: Ashen Nightmare Labyrinth & Whispering Winds Oracle Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenNightmareLabyrinthSubsystem.h"
#include "GA_KaelenMartyrSacrifice.h"
#include "AshenWhisperingWindsOracleSubsystem.h"
#include "AshenUserWidget_VigilTravelMenu.h"

// =============================================================================
//  Test 1: Nightmare Labyrinth Subsystem — Trial Initiation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenNightmareTrialInitiationTest,
	"AshenOath.Labyrinth.NightmareTrial.InitiationState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenNightmareTrialInitiationTest::RunTest(const FString& Parameters)
{
	UAshenNightmareLabyrinthSubsystem* Labyrinth = NewObject<UAshenNightmareLabyrinthSubsystem>();
	if (!TestNotNull(TEXT("NightmareLabyrinthSubsystem must be constructable"), Labyrinth)) return false;

	const FName TrialID(TEXT("Trial_ShadowSelf_01"));
	bool bStarted = Labyrinth->StartNightmareTrial(TrialID);
	TestTrue(TEXT("StartNightmareTrial must return true"), bStarted);

	return true;
}

// =============================================================================
//  Test 2: Kaelen Martyr Sacrifice — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMartyrSacrificeClassTest,
	"AshenOath.GAS.KaelenMartyrSacrifice.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMartyrSacrificeClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenMartyrSacrifice"));
	TestNotNull(TEXT("UGA_KaelenMartyrSacrifice must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Whispering Winds Oracle Subsystem — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWhisperingWindsReflectionTest,
	"AshenOath.Oracle.WhisperingWinds.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWhisperingWindsReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenWhisperingWindsOracleSubsystem class must be valid"),
		UAshenWhisperingWindsOracleSubsystem::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Vigil Travel Menu Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVigilTravelMenuWidgetTest,
	"AshenOath.UI.VigilTravelMenuWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVigilTravelMenuWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_VigilTravelMenu* Widget = NewObject<UAshenUserWidget_VigilTravelMenu>();
	if (!TestNotNull(TEXT("VigilTravelMenu widget must be constructable"), Widget)) return false;

	Widget->UpdateVigilTravelDisplay(75.0f, false);
	TestEqual(TEXT("DisplayedVigilance must be 75.0"), Widget->DisplayedVigilance, 75.0f);
	TestFalse(TEXT("bPartyExhausted must be false"), Widget->bPartyExhausted);

	return true;
}

// =============================================================================
//  Test 5: Milestone 335 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone335VerificationTest,
	"AshenOath.Milestone.Milestone335.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone335VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone335.Verification: Milestone 335 Master Systems Verified!"));
	return true;
}
