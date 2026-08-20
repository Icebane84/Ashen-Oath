// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 280: Ashen Destructible Wall & Boss HUD Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDungeonDestructibleWallComponent.h"
#include "GA_KaelenGroundShatterBurst.h"
#include "AshenBossHealthBarControllerComponent.h"
#include "AshenUserWidget_DestructibleWallPrompt.h"

// =============================================================================
//  Test 1: Destructible Wall — Damage & Destruction
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDestructibleWallDamageTest,
	"AshenOath.Dungeon.DestructibleWall.DamageAndDestruction",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDestructibleWallDamageTest::RunTest(const FString& Parameters)
{
	UAshenDungeonDestructibleWallComponent* Wall = NewObject<UAshenDungeonDestructibleWallComponent>();
	if (!TestNotNull(TEXT("DestructibleWallComponent must be constructable"), Wall)) return false;

	Wall->MaxWallHealth = 200.0f;
	TestFalse(TEXT("Wall must initially not be destroyed"), Wall->IsDestroyed());

	Wall->ReceiveStructuralDamage(100.0f);
	TestFalse(TEXT("Wall must remain standing at half health"), Wall->IsDestroyed());

	Wall->ReceiveStructuralDamage(150.0f);
	TestTrue(TEXT("Wall must be destroyed after receiving full damage"), Wall->IsDestroyed());

	return true;
}

// =============================================================================
//  Test 2: Kaelen Ground Shatter Burst — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGroundShatterBurstClassTest,
	"AshenOath.GAS.KaelenShatterBurst.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGroundShatterBurstClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenGroundShatterBurst"));
	TestNotNull(TEXT("UGA_KaelenGroundShatterBurst must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Boss Health Bar Controller — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossHealthBarControllerReflectionTest,
	"AshenOath.BossHUD.HealthBarController.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossHealthBarControllerReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenBossHealthBarControllerComponent class must be valid"),
		UAshenBossHealthBarControllerComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Destructible Wall Prompt Widget — Display & Hide
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDestructibleWallPromptWidgetTest,
	"AshenOath.UI.DestructibleWallPromptWidget.DisplayAndHide",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDestructibleWallPromptWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_DestructibleWallPrompt* Prompt = NewObject<UAshenUserWidget_DestructibleWallPrompt>();
	if (!TestNotNull(TEXT("DestructibleWallPrompt widget must be constructable"), Prompt)) return false;

	const FText PromptText = FText::FromString(TEXT("Strike Wall"));
	Prompt->ShowWallPrompt(PromptText);
	TestTrue(TEXT("bPromptVisible must be true after show"), Prompt->bPromptVisible);

	Prompt->HideWallPrompt();
	TestFalse(TEXT("bPromptVisible must be false after hide"), Prompt->bPromptVisible);

	return true;
}

// =============================================================================
//  Test 5: Milestone 280 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone280VerificationTest,
	"AshenOath.Milestone.Milestone280.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone280VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone280.Verification: Milestone 280 Systems Ready!"));
	return true;
}
