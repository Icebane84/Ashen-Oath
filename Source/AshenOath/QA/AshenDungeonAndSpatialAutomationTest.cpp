// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 235: Ashen Dungeon TrapDoor & Spatial Audio Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDungeonTrapDoorComponent.h"
#include "GA_GarrettExplosiveFlashPowder.h"
#include "AshenAudioSpatialVoiceComponent.h"
#include "AshenUserWidget_BossPhaseBanner.h"

// =============================================================================
//  Test 1: Trap Door Component — Triggering
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTrapDoorTriggerTest,
	"AshenOath.Dungeon.TrapDoor.Triggering",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTrapDoorTriggerTest::RunTest(const FString& Parameters)
{
	UAshenDungeonTrapDoorComponent* Trap = NewObject<UAshenDungeonTrapDoorComponent>();
	if (!TestNotNull(TEXT("DungeonTrapDoorComponent must be constructable"), Trap)) return false;

	TestFalse(TEXT("Trap door must initially not be triggered"), Trap->IsTrapTriggered());
	Trap->TriggerTrap(nullptr);
	TestTrue(TEXT("Trap door must be triggered after TriggerTrap"), Trap->IsTrapTriggered());

	return true;
}

// =============================================================================
//  Test 2: Garrett Explosive Flash Powder — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFlashPowderClassTest,
	"AshenOath.GAS.GarrettFlashPowder.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFlashPowderClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_GarrettExplosiveFlashPowder"));
	TestNotNull(TEXT("UGA_GarrettExplosiveFlashPowder must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Audio Spatial Voice — Distance Settings
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAudioSpatialVoiceDistanceTest,
	"AshenOath.Audio.SpatialVoice.MaxDistance",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAudioSpatialVoiceDistanceTest::RunTest(const FString& Parameters)
{
	UAshenAudioSpatialVoiceComponent* Voice = NewObject<UAshenAudioSpatialVoiceComponent>();
	if (!TestNotNull(TEXT("AudioSpatialVoiceComponent must be constructable"), Voice)) return false;

	TestEqual(TEXT("MaxVoiceDistance must default to 1500.0u"), Voice->MaxVoiceDistance, 1500.0f);
	return true;
}

// =============================================================================
//  Test 4: Boss Phase Banner Widget — Display & Dismiss
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossPhaseBannerWidgetTest,
	"AshenOath.UI.BossPhaseBannerWidget.DisplayAndDismiss",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossPhaseBannerWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_BossPhaseBanner* Banner = NewObject<UAshenUserWidget_BossPhaseBanner>();
	if (!TestNotNull(TEXT("BossPhaseBanner widget must be constructable"), Banner)) return false;

	const FText PhaseTitle = FText::FromString(TEXT("Unbound Corruption"));
	Banner->DisplayPhaseBanner(2, PhaseTitle);

	TestTrue(TEXT("bBannerActive must be true after display"), Banner->bBannerActive);
	TestEqual(TEXT("ActivePhaseIndex must be 2"), Banner->ActivePhaseIndex, 2);

	Banner->DismissPhaseBanner();
	TestFalse(TEXT("bBannerActive must be false after dismiss"), Banner->bBannerActive);

	return true;
}

// =============================================================================
//  Test 5: Trap Door Component — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTrapDoorReflectionTest,
	"AshenOath.Dungeon.TrapDoor.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTrapDoorReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenDungeonTrapDoorComponent class must be valid"),
		UAshenDungeonTrapDoorComponent::StaticClass() != nullptr);
	return true;
}
