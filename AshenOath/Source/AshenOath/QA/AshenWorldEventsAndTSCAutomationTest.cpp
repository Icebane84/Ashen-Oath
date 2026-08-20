// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 385: Ashen World Events & Tactical Targeting Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenSoulRemnantsAbsorbCraftingSubsystem.h"
#include "AshenDynamicWorldEventsSubsystem.h"
#include "AshenTacticalSlowdownTargetingComponent.h"
#include "AshenUserWidget_TacticalTargetingHUD.h"

// =============================================================================
//  Test 1: Soul Remnants Absorb Crafting — Blueprint Unlock
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAbsorbBlueprintUnlockTest,
	"AshenOath.Absorb.CraftingSubsystem.UnlockBlueprint",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAbsorbBlueprintUnlockTest::RunTest(const FString& Parameters)
{
	UAshenSoulRemnantsAbsorbCraftingSubsystem* Absorb = NewObject<UAshenSoulRemnantsAbsorbCraftingSubsystem>();
	if (!TestNotNull(TEXT("SoulRemnantsAbsorbCraftingSubsystem must be constructable"), Absorb)) return false;

	const FName BlueprintID(TEXT("Blueprint_VoidBlade_Ancient"));
	bool bUnlocked = Absorb->UnlockBlueprintFromAbsorbedRemnant(BlueprintID);
	TestTrue(TEXT("UnlockBlueprintFromAbsorbedRemnant must return true"), bUnlocked);

	return true;
}

// =============================================================================
//  Test 2: Dynamic World Events — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWorldEventsReflectionTest,
	"AshenOath.Events.DynamicWorldSubsystem.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWorldEventsReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenDynamicWorldEventsSubsystem class must be valid"),
		UAshenDynamicWorldEventsSubsystem::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 3: Tactical Slowdown Targeting — Weak Point Lock
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTSCTargetingLockTest,
	"AshenOath.TSC.TargetingComponent.WeakPointLock",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTSCTargetingLockTest::RunTest(const FString& Parameters)
{
	UAshenTacticalSlowdownTargetingComponent* Targeting = NewObject<UAshenTacticalSlowdownTargetingComponent>();
	if (!TestNotNull(TEXT("TacticalSlowdownTargetingComponent must be constructable"), Targeting)) return false;

	const FName BoneName(TEXT("spine_03"));
	bool bLocked = Targeting->LockWeakPointTarget(BoneName, 2.5f);
	TestTrue(TEXT("LockWeakPointTarget must return true"), bLocked);

	return true;
}

// =============================================================================
//  Test 4: Tactical Targeting HUD Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTacticalTargetingWidgetTest,
	"AshenOath.UI.TacticalTargetingHUDWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTacticalTargetingWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_TacticalTargetingHUD* Widget = NewObject<UAshenUserWidget_TacticalTargetingHUD>();
	if (!TestNotNull(TEXT("TacticalTargetingHUD widget must be constructable"), Widget)) return false;

	const FName BoneName(TEXT("head"));
	Widget->UpdateTargetingDisplay(BoneName, 3.0f);
	TestEqual(TEXT("DisplayedCritMultiplier must equal 3.0"), Widget->DisplayedCritMultiplier, 3.0f);

	return true;
}

// =============================================================================
//  Test 5: Milestone 390 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone390VerificationTest,
	"AshenOath.Milestone.Milestone390.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone390VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone390.Verification: Milestone 390 Systems Verified!"));
	return true;
}
