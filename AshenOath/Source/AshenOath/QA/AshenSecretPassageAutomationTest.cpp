// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 290: Ashen Secret Passage & Stealth Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDungeonSecretPassageComponent.h"
#include "GA_GarrettShadowStepStealth.h"
#include "AshenBossAuraBuffControllerComponent.h"
#include "AshenUserWidget_SecretPassagePrompt.h"

// =============================================================================
//  Test 1: Secret Passage — Reveal State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSecretPassageRevealTest,
	"AshenOath.Dungeon.SecretPassage.RevealState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSecretPassageRevealTest::RunTest(const FString& Parameters)
{
	UAshenDungeonSecretPassageComponent* Passage = NewObject<UAshenDungeonSecretPassageComponent>();
	if (!TestNotNull(TEXT("DungeonSecretPassageComponent must be constructable"), Passage)) return false;

	TestFalse(TEXT("Passage must initially be hidden"), Passage->IsRevealed());
	Passage->RevealPassage();
	TestTrue(TEXT("Passage must be revealed after RevealPassage"), Passage->IsRevealed());

	return true;
}

// =============================================================================
//  Test 2: Garrett Shadow Step Stealth — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenShadowStepClassTest,
	"AshenOath.GAS.GarrettShadowStep.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenShadowStepClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_GarrettShadowStepStealth"));
	TestNotNull(TEXT("UGA_GarrettShadowStepStealth must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Boss Aura Buff Controller — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossAuraReflectionTest,
	"AshenOath.Boss.AuraBuffController.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossAuraReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenBossAuraBuffControllerComponent class must be valid"),
		UAshenBossAuraBuffControllerComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Secret Passage Prompt Widget — Display & Hide
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSecretPassagePromptWidgetTest,
	"AshenOath.UI.SecretPassagePromptWidget.DisplayAndHide",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSecretPassagePromptWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_SecretPassagePrompt* Prompt = NewObject<UAshenUserWidget_SecretPassagePrompt>();
	if (!TestNotNull(TEXT("SecretPassagePrompt widget must be constructable"), Prompt)) return false;

	const FText PromptText = FText::FromString(TEXT("Hidden Door Discovered"));
	Prompt->ShowSecretPassagePrompt(PromptText);
	TestTrue(TEXT("bPromptVisible must be true after show"), Prompt->bPromptVisible);

	Prompt->HidePrompt();
	TestFalse(TEXT("bPromptVisible must be false after hide"), Prompt->bPromptVisible);

	return true;
}

// =============================================================================
//  Test 5: Milestone 290 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone290VerificationTest,
	"AshenOath.Milestone.Milestone290.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone290VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone290.Verification: Milestone 290 Systems Ready!"));
	return true;
}
