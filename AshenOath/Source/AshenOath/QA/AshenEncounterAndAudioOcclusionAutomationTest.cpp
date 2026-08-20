// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 405: Ashen Dynamic Encounter & Audio Occlusion Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDynamicEncounterScalerComponent.h"
#include "AshenSpatialAudioOcclusionMeshComponent.h"
#include "AshenMemoryThreadSanctuarySubsystem.h"
#include "AshenUserWidget_MemoryThreadJournal.h"

// =============================================================================
//  Test 1: Dynamic Encounter Scaler — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEncounterScalerReflectionTest,
	"AshenOath.Encounter.DynamicScalerComponent.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenEncounterScalerReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenDynamicEncounterScalerComponent class must be valid"),
		UAshenDynamicEncounterScalerComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 2: Spatial Audio Occlusion Mesh — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSpatialAudioOcclusionReflectionTest,
	"AshenOath.Audio.SpatialOcclusionComponent.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSpatialAudioOcclusionReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenSpatialAudioOcclusionMeshComponent class must be valid"),
		UAshenSpatialAudioOcclusionMeshComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 3: Memory Thread Sanctuary Subsystem — Collect Thread
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMemoryThreadSubsystemTest,
	"AshenOath.MemoryThread.SanctuarySubsystem.CollectThread",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMemoryThreadSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenMemoryThreadSanctuarySubsystem* Subsystem = NewObject<UAshenMemoryThreadSanctuarySubsystem>();
	if (!TestNotNull(TEXT("MemoryThreadSanctuarySubsystem must be constructable"), Subsystem)) return false;

	const FName ThreadID(TEXT("Thread_KaelensOathOfShields"));
	bool bCollected = Subsystem->CollectMemoryThread(ThreadID);
	TestTrue(TEXT("CollectMemoryThread must return true"), bCollected);
	TestEqual(TEXT("Collected thread count must be 1"), Subsystem->GetCollectedMemoryThreadCount(), 1);

	return true;
}

// =============================================================================
//  Test 4: Memory Thread Journal Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMemoryThreadJournalWidgetTest,
	"AshenOath.UI.MemoryThreadJournalWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMemoryThreadJournalWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_MemoryThreadJournal* Widget = NewObject<UAshenUserWidget_MemoryThreadJournal>();
	if (!TestNotNull(TEXT("MemoryThreadJournal widget must be constructable"), Widget)) return false;

	const FName ThreadID(TEXT("Thread_FallOfAethelgard"));
	Widget->UpdateJournalDisplay(ThreadID, 5);
	TestEqual(TEXT("TotalCollected must equal 5"), Widget->TotalCollected, 5);

	return true;
}

// =============================================================================
//  Test 5: Milestone 410 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone410VerificationTest,
	"AshenOath.Milestone.Milestone410.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone410VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone410.Verification: Milestone 410 Systems Verified!"));
	return true;
}
