// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 191: Ashen Quest & World Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenQuestJournalSubsystem.h"
#include "GA_SerafinaSacredGround.h"
#include "AshenWeatherFXControllerComponent.h"
#include "AshenUserWidget_QuestTracker.h"

// =============================================================================
//  Test 1: Quest Journal Subsystem — Lifecycle
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenQuestJournalLifecycleTest,
	"AshenOath.Quest.JournalSubsystem.Lifecycle",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenQuestJournalLifecycleTest::RunTest(const FString& Parameters)
{
	UAshenQuestJournalSubsystem* Subsystem = NewObject<UAshenQuestJournalSubsystem>();
	if (!TestNotNull(TEXT("QuestJournalSubsystem must be constructable"), Subsystem)) return false;

	const FName QuestID(TEXT("Quest_FrozenTarn_01"));
	Subsystem->RegisterQuest(QuestID, TEXT("The Echoes of Frozen Tarn"));

	TestEqual(TEXT("Quest initial state must be NotStarted"), Subsystem->GetQuestState(QuestID), EAshenQuestState::NotStarted);

	Subsystem->StartQuest(QuestID);
	TestEqual(TEXT("Quest state must be Active after StartQuest"), Subsystem->GetQuestState(QuestID), EAshenQuestState::Active);

	Subsystem->CompleteQuest(QuestID);
	TestEqual(TEXT("Quest state must be Completed after CompleteQuest"), Subsystem->GetQuestState(QuestID), EAshenQuestState::Completed);

	return true;
}

// =============================================================================
//  Test 2: Quest Journal Subsystem — Objective Tracking
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenQuestObjectiveTrackingTest,
	"AshenOath.Quest.JournalSubsystem.ObjectiveTracking",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenQuestObjectiveTrackingTest::RunTest(const FString& Parameters)
{
	UAshenQuestJournalSubsystem* Subsystem = NewObject<UAshenQuestJournalSubsystem>();
	if (!TestNotNull(TEXT("QuestJournalSubsystem must be constructable"), Subsystem)) return false;

	const FName QuestID(TEXT("Quest_Mindscape_01"));
	const FName ObjID(TEXT("Obj_DefeatBoss"));

	Subsystem->RegisterQuest(QuestID, TEXT("Mindscape Collapse"));
	Subsystem->StartQuest(QuestID);
	Subsystem->AddObjective(QuestID, ObjID, TEXT("Defeat the Shroud Knight"));

	bool bResult = Subsystem->CompleteObjective(QuestID, ObjID);
	TestTrue(TEXT("CompleteObjective must return true for valid objective"), bResult);

	return true;
}

// =============================================================================
//  Test 3: Serafina Sacred Ground — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSacredGroundClassTest,
	"AshenOath.GAS.SerafinaSacredGround.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSacredGroundClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaSacredGround"));
	TestNotNull(TEXT("UGA_SerafinaSacredGround must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 4: Weather FX Controller — Intensity Modulation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeatherFXIntensityTest,
	"AshenOath.Weather.FXController.IntensityModulation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWeatherFXIntensityTest::RunTest(const FString& Parameters)
{
	UAshenWeatherFXControllerComponent* Controller = NewObject<UAshenWeatherFXControllerComponent>();
	if (!TestNotNull(TEXT("WeatherFXControllerComponent must be constructable"), Controller)) return false;

	Controller->ApplyWeatherFX(EAshenWeatherState::HeavyBlizzard, 0.75f);
	TestEqual(TEXT("Weather type must be HeavyBlizzard"), Controller->GetCurrentWeatherType(), EAshenWeatherState::HeavyBlizzard);
	TestEqual(TEXT("Intensity must be 0.75"), Controller->GetCurrentIntensity(), 0.75f);

	return true;
}

// =============================================================================
//  Test 5: Quest Tracker Widget — Display & Clear
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenQuestTrackerWidgetTest,
	"AshenOath.UI.QuestTrackerWidget.DisplayAndClear",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenQuestTrackerWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_QuestTracker* Widget = NewObject<UAshenUserWidget_QuestTracker>();
	if (!TestNotNull(TEXT("QuestTracker widget must be constructable"), Widget)) return false;

	const FName QuestID(TEXT("Quest_01"));
	const FText Title = FText::FromString(TEXT("Path of Ashes"));
	const FText ObjText = FText::FromString(TEXT("Find Sanctuary"));

	Widget->DisplayActiveQuest(QuestID, Title, ObjText);
	TestEqual(TEXT("CurrentQuestID must match"), Widget->CurrentQuestID, QuestID);

	Widget->ClearQuestDisplay();
	TestEqual(TEXT("CurrentQuestID must be None after clear"), Widget->CurrentQuestID, FName(NAME_None));

	return true;
}
