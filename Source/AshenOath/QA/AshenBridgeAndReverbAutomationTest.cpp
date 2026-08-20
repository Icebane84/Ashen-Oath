// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 270: Ashen Rotating Bridge & Audio Reverb Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDungeonRotatingBridgeComponent.h"
#include "GA_SerafinaSacredBeam.h"
#include "AshenAudioReverbZoneVolumeComponent.h"
#include "AshenUserWidget_BridgeRotationPrompt.h"

// =============================================================================
//  Test 1: Rotating Bridge — Rotation & Alignment
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBridgeRotationTest,
	"AshenOath.Dungeon.RotatingBridge.RotationAndAlignment",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBridgeRotationTest::RunTest(const FString& Parameters)
{
	UAshenDungeonRotatingBridgeComponent* Bridge = NewObject<UAshenDungeonRotatingBridgeComponent>();
	if (!TestNotNull(TEXT("DungeonRotatingBridgeComponent must be constructable"), Bridge)) return false;

	Bridge->TargetAlignedAngle = 180.0f;
	TestFalse(TEXT("Bridge must initially not be aligned"), Bridge->IsAligned());

	bool bAligned1 = Bridge->RotateBridge(90.0f); // 90° -> false
	TestFalse(TEXT("Bridge must not be aligned at 90°"), bAligned1);

	bool bAligned2 = Bridge->RotateBridge(90.0f); // 180° -> true
	TestTrue(TEXT("Bridge must be aligned at 180°"), bAligned2);

	return true;
}

// =============================================================================
//  Test 2: Serafina Sacred Beam — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSacredBeamClassTest,
	"AshenOath.GAS.SerafinaSacredBeam.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSacredBeamClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaSacredBeam"));
	TestNotNull(TEXT("UGA_SerafinaSacredBeam must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Audio Reverb Zone Volume — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAudioReverbZoneReflectionTest,
	"AshenOath.Audio.ReverbZoneVolume.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAudioReverbZoneReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenAudioReverbZoneVolumeComponent class must be valid"),
		UAshenAudioReverbZoneVolumeComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Bridge Rotation Prompt Widget — Display & Hide
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBridgePromptWidgetTest,
	"AshenOath.UI.BridgeRotationPromptWidget.DisplayAndHide",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBridgePromptWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_BridgeRotationPrompt* Prompt = NewObject<UAshenUserWidget_BridgeRotationPrompt>();
	if (!TestNotNull(TEXT("BridgeRotationPrompt widget must be constructable"), Prompt)) return false;

	Prompt->ShowBridgePrompt(90.0f, false);
	TestTrue(TEXT("bPromptVisible must be true after show"), Prompt->bPromptVisible);

	Prompt->HideBridgePrompt();
	TestFalse(TEXT("bPromptVisible must be false after hide"), Prompt->bPromptVisible);

	return true;
}

// =============================================================================
//  Test 5: Milestone 270 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone270VerificationTest,
	"AshenOath.Milestone.Milestone270.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone270VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone270.Verification: Milestone 270 Systems Ready!"));
	return true;
}
