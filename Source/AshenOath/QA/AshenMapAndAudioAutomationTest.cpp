// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 205: Ashen Map, Audio & Compass Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenFastTravelMapWidget.h"
#include "GA_SerafinaAegisShield.h"
#include "AshenAudioReverbSubsystem.h"
#include "AshenUserWidget_CompassMarker.h"

// =============================================================================
//  Test 1: Fast Travel Map Widget — Node Selection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFastTravelMapSelectionTest,
	"AshenOath.UI.FastTravelMap.NodeSelection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFastTravelMapSelectionTest::RunTest(const FString& Parameters)
{
	UAshenFastTravelMapWidget* MapWidget = NewObject<UAshenFastTravelMapWidget>();
	if (!TestNotNull(TEXT("FastTravelMap widget must be constructable"), MapWidget)) return false;

	const FName TargetID(TEXT("Campfire_FrozenTarn_02"));
	MapWidget->SelectSanctuaryNode(TargetID);

	TestEqual(TEXT("SelectedSanctuaryID must match"), MapWidget->SelectedSanctuaryID, TargetID);
	return true;
}

// =============================================================================
//  Test 2: Serafina Aegis Shield — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAegisShieldClassTest,
	"AshenOath.GAS.SerafinaAegis.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAegisShieldClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaAegisShield"));
	TestNotNull(TEXT("UGA_SerafinaAegisShield must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Audio Reverb Subsystem — Preset Change
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAudioReverbPresetTest,
	"AshenOath.Audio.ReverbSubsystem.PresetChange",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAudioReverbPresetTest::RunTest(const FString& Parameters)
{
	UAshenAudioReverbSubsystem* Subsystem = NewObject<UAshenAudioReverbSubsystem>();
	if (!TestNotNull(TEXT("AudioReverbSubsystem must be constructable"), Subsystem)) return false;

	TestEqual(TEXT("Default preset must be OpenAir"), Subsystem->GetCurrentPreset(), EAshenReverbPreset::OpenAir);

	Subsystem->SetReverbPreset(EAshenReverbPreset::CaveCathedral);
	TestEqual(TEXT("Preset must be CaveCathedral after SetReverbPreset"), Subsystem->GetCurrentPreset(), EAshenReverbPreset::CaveCathedral);

	return true;
}

// =============================================================================
//  Test 4: Compass Marker Widget — Setup & Offset
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCompassMarkerSetupTest,
	"AshenOath.UI.CompassMarker.SetupAndOffset",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCompassMarkerSetupTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_CompassMarker* Marker = NewObject<UAshenUserWidget_CompassMarker>();
	if (!TestNotNull(TEXT("CompassMarker widget must be constructable"), Marker)) return false;

	const FName MarkerID(TEXT("Quest_Goal_01"));
	const FVector Location(500.0f, 1000.0f, 200.0f);

	Marker->SetupMarker(MarkerID, EAshenCompassMarkerType::QuestGoal, Location);
	TestEqual(TEXT("MarkerID must match"), Marker->CurrentMarkerID, MarkerID);

	Marker->UpdateScreenOffset(0.25f, 45.0f);
	TestEqual(TEXT("CurrentNormalizedOffset must match"), Marker->CurrentNormalizedOffset, 0.25f);
	TestEqual(TEXT("CurrentDistanceMeters must match"), Marker->CurrentDistanceMeters, 45.0f);

	return true;
}

// =============================================================================
//  Test 5: Audio Reverb Subsystem — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAudioReverbReflectionTest,
	"AshenOath.Audio.ReverbSubsystem.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAudioReverbReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenAudioReverbSubsystem class must be valid"),
		UAshenAudioReverbSubsystem::StaticClass() != nullptr);

	UFunction* SetFn = UAshenAudioReverbSubsystem::StaticClass()->FindFunctionByName(FName("SetReverbPreset"));
	TestNotNull(TEXT("SetReverbPreset must be a registered UFUNCTION"), SetFn);

	return true;
}
