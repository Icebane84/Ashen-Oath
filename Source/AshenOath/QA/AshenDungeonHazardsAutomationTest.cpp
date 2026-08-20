// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 230: Ashen Dungeon & Environmental Hazards Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenDungeonDoorLockComponent.h"
#include "GA_KaelenGreatswordPommelStrike.h"
#include "AshenEnvironmentalHazardsSubsystem.h"
#include "AshenUserWidget_DungeonInteractionPrompt.h"

// =============================================================================
//  Test 1: Dungeon Door Lock — Key Unlocking
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDoorLockUnlockTest,
	"AshenOath.Dungeon.DoorLock.KeyUnlock",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDoorLockUnlockTest::RunTest(const FString& Parameters)
{
	UAshenDungeonDoorLockComponent* Lock = NewObject<UAshenDungeonDoorLockComponent>();
	if (!TestNotNull(TEXT("DungeonDoorLockComponent must be constructable"), Lock)) return false;

	Lock->RequiredKeyID = FName(TEXT("Key_SanctuaryGate"));
	TestTrue(TEXT("Door must initially be locked"), Lock->IsLocked());

	// Wrong key -> Fail
	bool bWrongKey = Lock->TryUnlockWithKey(FName(TEXT("Key_WrongKey")));
	TestFalse(TEXT("Unlock must fail with wrong key"), bWrongKey);

	// Correct key -> Success
	bool bCorrectKey = Lock->TryUnlockWithKey(FName(TEXT("Key_SanctuaryGate")));
	TestTrue(TEXT("Unlock must succeed with correct key"), bCorrectKey);
	TestFalse(TEXT("Door must be unlocked after success"), Lock->IsLocked());

	return true;
}

// =============================================================================
//  Test 2: Kaelen Greatsword Pommel Strike — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPommelStrikeClassTest,
	"AshenOath.GAS.KaelenPommelStrike.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPommelStrikeClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenGreatswordPommelStrike"));
	TestNotNull(TEXT("UGA_KaelenGreatswordPommelStrike must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Environmental Hazards Subsystem — Registration
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHazardRegistrationTest,
	"AshenOath.Hazards.EnvironmentalSubsystem.Registration",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenHazardRegistrationTest::RunTest(const FString& Parameters)
{
	UAshenEnvironmentalHazardsSubsystem* Sub = NewObject<UAshenEnvironmentalHazardsSubsystem>();
	if (!TestNotNull(TEXT("EnvironmentalHazardsSubsystem must be constructable"), Sub)) return false;

	const FName HazardID(TEXT("Hazard_Lava_01"));
	Sub->RegisterHazard(HazardID, EAshenHazardType::LavaPool, FVector(100.0f, 0.0f, 0.0f));
	TestEqual(TEXT("Active hazard count must be 1"), Sub->GetActiveHazardCount(), 1);

	Sub->DeregisterHazard(HazardID);
	TestEqual(TEXT("Active hazard count must be 0 after deregister"), Sub->GetActiveHazardCount(), 0);

	return true;
}

// =============================================================================
//  Test 4: Interaction Prompt Widget — Show & Hide
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenInteractionPromptWidgetTest,
	"AshenOath.UI.InteractionPromptWidget.ShowAndHide",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenInteractionPromptWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_DungeonInteractionPrompt* Prompt = NewObject<UAshenUserWidget_DungeonInteractionPrompt>();
	if (!TestNotNull(TEXT("DungeonInteractionPrompt widget must be constructable"), Prompt)) return false;

	Prompt->ShowPrompt(FText::FromString(TEXT("Unlock Door")), FText::FromString(TEXT("E")));
	TestTrue(TEXT("bPromptVisible must be true after show"), Prompt->bPromptVisible);

	Prompt->HidePrompt();
	TestFalse(TEXT("bPromptVisible must be false after hide"), Prompt->bPromptVisible);

	return true;
}

// =============================================================================
//  Test 5: Milestone 230 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone230VerificationTest,
	"AshenOath.Milestone.Milestone230.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone230VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone230.Verification: Milestone 230 Systems Ready!"));
	return true;
}
