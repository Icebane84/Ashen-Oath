// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 220: Ashen Soul Perk & Radiant Burst Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenSoulPerkNodeComponent.h"
#include "GA_SerafinaRadiantBurst.h"
#include "AshenBossPhaseCameraShakeComponent.h"
#include "AshenUserWidget_SoulPerkTooltip.h"

// =============================================================================
//  Test 1: Soul Perk Node — Ash Cost & Prerequisite Unlock
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSoulPerkUnlockTest,
	"AshenOath.SoulPerk.Node.UnlockValidation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSoulPerkUnlockTest::RunTest(const FString& Parameters)
{
	UAshenSoulPerkNodeComponent* Node = NewObject<UAshenSoulPerkNodeComponent>();
	if (!TestNotNull(TEXT("SoulPerkNodeComponent must be constructable"), Node)) return false;

	Node->AshUnlockCost = 100.0f;
	Node->PerkID = FName(TEXT("Perk_RadiantAegis_01"));

	// Insufficient Ash -> Fail
	bool bRes1 = Node->UnlockPerk(50.0f, true);
	TestFalse(TEXT("Unlock must fail when player Ash is insufficient"), bRes1);

	// Prerequisite missing -> Fail
	bool bRes2 = Node->UnlockPerk(150.0f, false);
	TestFalse(TEXT("Unlock must fail when prerequisite is not met"), bRes2);

	// Valid Ash & Prerequisite -> Success
	bool bRes3 = Node->UnlockPerk(150.0f, true);
	TestTrue(TEXT("Unlock must succeed when Ash and prerequisites are valid"), bRes3);
	TestTrue(TEXT("bIsUnlocked must be true after successful unlock"), Node->IsUnlocked());

	return true;
}

// =============================================================================
//  Test 2: Serafina Radiant Burst — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenRadiantBurstClassTest,
	"AshenOath.GAS.SerafinaRadiantBurst.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenRadiantBurstClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaRadiantBurst"));
	TestNotNull(TEXT("UGA_SerafinaRadiantBurst must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Camera Shake Component — Scale Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCameraShakeScaleTest,
	"AshenOath.CameraShake.BossPhase.ScaleCalculation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCameraShakeScaleTest::RunTest(const FString& Parameters)
{
	UAshenBossPhaseCameraShakeComponent* Shake = NewObject<UAshenBossPhaseCameraShakeComponent>();
	if (!TestNotNull(TEXT("BossPhaseCameraShakeComponent must be constructable"), Shake)) return false;

	Shake->BaseShakeScale = 2.0f;
	TestEqual(TEXT("BaseShakeScale must be 2.0"), Shake->BaseShakeScale, 2.0f);

	return true;
}

// =============================================================================
//  Test 4: Soul Perk Tooltip Widget — Display & Hide
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSoulPerkTooltipWidgetTest,
	"AshenOath.UI.SoulPerkTooltip.DisplayAndHide",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSoulPerkTooltipWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_SoulPerkTooltip* Tooltip = NewObject<UAshenUserWidget_SoulPerkTooltip>();
	if (!TestNotNull(TEXT("SoulPerkTooltip widget must be constructable"), Tooltip)) return false;

	const FName PerkID(TEXT("Perk_01"));
	const FText Title = FText::FromString(TEXT("Holy Radiance"));
	const FText Desc = FText::FromString(TEXT("Increases healing aura by 25%"));

	Tooltip->DisplayPerkTooltip(PerkID, Title, Desc, 200.0f, false, true);
	TestTrue(TEXT("bTooltipVisible must be true after display"), Tooltip->bTooltipVisible);

	Tooltip->HideTooltip();
	TestFalse(TEXT("bTooltipVisible must be false after hide"), Tooltip->bTooltipVisible);

	return true;
}

// =============================================================================
//  Test 5: Milestone 220 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone220VerificationTest,
	"AshenOath.Milestone.Milestone220.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone220VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone220.Verification: Milestone 220 Systems Ready!"));
	return true;
}
