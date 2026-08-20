// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 215: Ashen Sanctuary Beacon & Sanity Audio Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenFastTravelSanctuaryBeacon.h"
#include "GA_KaelenGroundShatterStrike.h"
#include "AshenSanityCorruptedAudioComponent.h"
#include "AshenUserWidget_FastTravelNotification.h"

// =============================================================================
//  Test 1: Sanctuary Beacon — Activation State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSanctuaryBeaconActivationTest,
	"AshenOath.Sanctuary.Beacon.ActivationState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSanctuaryBeaconActivationTest::RunTest(const FString& Parameters)
{
	UAshenFastTravelSanctuaryBeacon* Beacon = NewObject<UAshenFastTravelSanctuaryBeacon>();
	if (!TestNotNull(TEXT("FastTravelSanctuaryBeacon must be constructable"), Beacon)) return false;

	TestFalse(TEXT("Beacon must not be activated initially"), Beacon->IsActivated());
	Beacon->ActivateBeacon();
	TestTrue(TEXT("Beacon must be activated after ActivateBeacon"), Beacon->IsActivated());

	return true;
}

// =============================================================================
//  Test 2: Ground Shatter Strike — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGroundShatterClassTest,
	"AshenOath.GAS.KaelenGroundShatter.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGroundShatterClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenGroundShatterStrike"));
	TestNotNull(TEXT("UGA_KaelenGroundShatterStrike must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Sanity Corrupted Audio — Pitch Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSanityAudioPitchTest,
	"AshenOath.Audio.SanityCorrupted.PitchCalculation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSanityAudioPitchTest::RunTest(const FString& Parameters)
{
	UAshenSanityCorruptedAudioComponent* AudioComp = NewObject<UAshenSanityCorruptedAudioComponent>();
	if (!TestNotNull(TEXT("SanityCorruptedAudioComponent must be constructable"), AudioComp)) return false;

	AudioComp->MinPitch = 0.50f;
	AudioComp->MaxPitch = 1.00f;

	AudioComp->UpdateAudioCorruption(100.0f, 100.0f); // 100% sanity -> MaxPitch 1.0
	TestEqual(TEXT("Pitch must be 1.0 for full sanity"), AudioComp->GetAudioPitchMultiplier(), 1.00f);

	AudioComp->UpdateAudioCorruption(0.0f, 100.0f); // 0% sanity -> MinPitch 0.5
	TestEqual(TEXT("Pitch must be 0.5 for zero sanity"), AudioComp->GetAudioPitchMultiplier(), 0.50f);

	return true;
}

// =============================================================================
//  Test 4: Fast Travel Notification Widget — Display & Dismiss
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFastTravelNotificationWidgetTest,
	"AshenOath.UI.FastTravelNotificationWidget.DisplayAndDismiss",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenFastTravelNotificationWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_FastTravelNotification* Widget = NewObject<UAshenUserWidget_FastTravelNotification>();
	if (!TestNotNull(TEXT("FastTravelNotification widget must be constructable"), Widget)) return false;

	const FName BeaconID(TEXT("Sanctuary_01"));
	const FText BeaconName = FText::FromString(TEXT("Highland Rest"));

	Widget->DisplaySanctuaryUnlockedNotification(BeaconID, BeaconName);
	TestTrue(TEXT("bNotificationActive must be true after display"), Widget->bNotificationActive);

	Widget->DismissNotification();
	TestFalse(TEXT("bNotificationActive must be false after dismiss"), Widget->bNotificationActive);

	return true;
}

// =============================================================================
//  Test 5: Sanctuary Beacon — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSanctuaryBeaconReflectionTest,
	"AshenOath.Sanctuary.Beacon.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSanctuaryBeaconReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenFastTravelSanctuaryBeacon class must be valid"),
		UAshenFastTravelSanctuaryBeacon::StaticClass() != nullptr);
	return true;
}
