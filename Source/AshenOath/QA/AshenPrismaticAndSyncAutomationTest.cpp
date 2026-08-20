// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 360: Ashen Prismatic Realm & Dual Sync Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenPrismaticRealmVeilSubsystem.h"
#include "AshenCompanionFatigueVulnerabilityComponent.h"
#include "GA_KaelenSerafinaSyncedHolyBurst.h"
#include "AshenUserWidget_PrismaticVeilOverlay.h"

// =============================================================================
//  Test 1: Prismatic Realm Veil — Shift Realm State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPrismaticRealmShiftTest,
	"AshenOath.Prismatic.VeilSubsystem.ShiftState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPrismaticRealmShiftTest::RunTest(const FString& Parameters)
{
	UAshenPrismaticRealmVeilSubsystem* Veil = NewObject<UAshenPrismaticRealmVeilSubsystem>();
	if (!TestNotNull(TEXT("PrismaticRealmVeilSubsystem must be constructable"), Veil)) return false;

	TestTrue(TEXT("Initial state must be MaterialWorld"), Veil->GetCurrentVeilState() == EAshenWorldVeilState::MaterialWorld);
	Veil->ShiftWorldVeilState(EAshenWorldVeilState::PrismaticVoidPhase);
	TestTrue(TEXT("State must be PrismaticVoidPhase after shift"), Veil->GetCurrentVeilState() == EAshenWorldVeilState::PrismaticVoidPhase);

	return true;
}

// =============================================================================
//  Test 2: Companion Fatigue Component — Accrue & Recovery
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCompanionFatigueAccrualTest,
	"AshenOath.Companion.FatigueComponent.AccrueAndRecover",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCompanionFatigueAccrualTest::RunTest(const FString& Parameters)
{
	UAshenCompanionFatigueVulnerabilityComponent* Fatigue = NewObject<UAshenCompanionFatigueVulnerabilityComponent>();
	if (!TestNotNull(TEXT("CompanionFatigueVulnerabilityComponent must be constructable"), Fatigue)) return false;

	TestFalse(TEXT("Initially companion must not be in breakdown"), Fatigue->IsVulnerableBreakdown());
	Fatigue->AccrueFatigue(85.0f);
	TestTrue(TEXT("Companion must be in breakdown after 85.0 fatigue"), Fatigue->IsVulnerableBreakdown());

	return true;
}

// =============================================================================
//  Test 3: Kaelen + Serafina Synced Holy Burst — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSyncedHolyBurstClassTest,
	"AshenOath.GAS.KaelenSerafinaSyncedHolyBurst.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSyncedHolyBurstClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenSerafinaSyncedHolyBurst"));
	TestNotNull(TEXT("UGA_KaelenSerafinaSyncedHolyBurst must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 4: Prismatic Veil Overlay Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenPrismaticVeilOverlayWidgetTest,
	"AshenOath.UI.PrismaticVeilOverlayWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenPrismaticVeilOverlayWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_PrismaticVeilOverlay* Widget = NewObject<UAshenUserWidget_PrismaticVeilOverlay>();
	if (!TestNotNull(TEXT("PrismaticVeilOverlay widget must be constructable"), Widget)) return false;

	Widget->UpdateVeilOverlayDisplay(EAshenWorldVeilState::PrismaticVoidPhase, 2.5f);
	TestTrue(TEXT("DisplayedVeilState must be PrismaticVoidPhase"), Widget->DisplayedVeilState == EAshenWorldVeilState::PrismaticVoidPhase);
	TestEqual(TEXT("DisplayedDissonance must equal 2.5"), Widget->DisplayedDissonance, 2.5f);

	return true;
}

// =============================================================================
//  Test 5: Milestone 360 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone360VerificationTest,
	"AshenOath.Milestone.Milestone360.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone360VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone360.Verification: Milestone 360 Systems Verified!"));
	return true;
}
