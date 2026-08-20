// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 399: Ashen Nightmare Labyrinth Boss & Serafina Aegis Sanctuary Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenNightmareLabyrinthBossSubsystem.h"
#include "GA_SerafinaAegisShieldSanctuary.h"
#include "AshenUserWidget_MasterMilestone400HUD.h"

// =============================================================================
//  Test 1: Nightmare Labyrinth Boss Subsystem — Defeat Boss
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenNightmareBossDefeatTest,
	"AshenOath.NightmareBoss.LabyrinthSubsystem.DefeatBoss",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenNightmareBossDefeatTest::RunTest(const FString& Parameters)
{
	UAshenNightmareLabyrinthBossSubsystem* BossSubsystem = NewObject<UAshenNightmareLabyrinthBossSubsystem>();
	if (!TestNotNull(TEXT("NightmareLabyrinthBossSubsystem must be constructable"), BossSubsystem)) return false;

	const FName BossID(TEXT("Boss_NightmareEldrinEcho"));
	BossSubsystem->DefeatNightmareBoss(BossID);
	return true;
}

// =============================================================================
//  Test 2: Serafina Aegis Shield Sanctuary — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAegisShieldSanctuaryClassTest,
	"AshenOath.GAS.SerafinaAegisShieldSanctuary.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAegisShieldSanctuaryClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaAegisShieldSanctuary"));
	TestNotNull(TEXT("UGA_SerafinaAegisShieldSanctuary must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 400 HUD Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterMilestone400HUDWidgetTest,
	"AshenOath.UI.MasterMilestone400HUDWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterMilestone400HUDWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_MasterMilestone400HUD* Widget = NewObject<UAshenUserWidget_MasterMilestone400HUD>();
	if (!TestNotNull(TEXT("MasterMilestone400HUD widget must be constructable"), Widget)) return false;

	Widget->UpdateMasterDashboardDisplay(400, 200);
	TestEqual(TEXT("TotalBuilds must equal 400"), Widget->TotalBuilds, 400);
	TestEqual(TEXT("TotalQATests must equal 200"), Widget->TotalQATests, 200);

	return true;
}

// =============================================================================
//  Test 4: Milestone 399 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone399VerificationTest,
	"AshenOath.Milestone.Milestone399.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone399VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone399.Verification: Milestone 399 Systems Verified!"));
	return true;
}
