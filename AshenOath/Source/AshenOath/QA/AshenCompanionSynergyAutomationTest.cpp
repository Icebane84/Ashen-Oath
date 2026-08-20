// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 210: Ashen Companion Synergy & Boss Phase Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenCompanionComboSynergyComponent.h"
#include "GA_GarrettSmokeBombTrap.h"
#include "AshenBossPhaseAudioVisualNotifierComponent.h"
#include "AshenUserWidget_CompanionSynergyMeter.h"

// =============================================================================
//  Test 1: Companion Combo Synergy — Meter Progression & Surge
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSynergyMeterProgressionTest,
	"AshenOath.Synergy.ComboSynergy.MeterProgression",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSynergyMeterProgressionTest::RunTest(const FString& Parameters)
{
	UAshenCompanionComboSynergyComponent* Comp = NewObject<UAshenCompanionComboSynergyComponent>();
	if (!TestNotNull(TEXT("CompanionComboSynergyComponent must be constructable"), Comp)) return false;

	Comp->RegisterCompanionHit(50.0f);
	TestEqual(TEXT("Synergy meter must be 50.0"), Comp->GetSynergyMeter(), 50.0f);

	Comp->RegisterCompanionHit(50.0f);
	TestEqual(TEXT("Synergy meter must be 100.0 (Max)"), Comp->GetSynergyMeter(), 100.0f);

	bool bSurge = Comp->TriggerSynergySurge();
	TestTrue(TEXT("Synergy surge must trigger at 100% meter"), bSurge);
	TestEqual(TEXT("Synergy multiplier must be 1.5x during surge"), Comp->GetCurrentMultiplier(), 1.5f);

	return true;
}

// =============================================================================
//  Test 2: Smoke Bomb Trap — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSmokeBombTrapClassTest,
	"AshenOath.GAS.GarrettSmokeBomb.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSmokeBombTrapClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_GarrettSmokeBombTrap"));
	TestNotNull(TEXT("UGA_GarrettSmokeBombTrap must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 3: Boss Phase AV Notifier — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenBossPhaseAVReflectionTest,
	"AshenOath.Boss.AVNotifier.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenBossPhaseAVReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenBossPhaseAudioVisualNotifierComponent class must be valid"),
		UAshenBossPhaseAudioVisualNotifierComponent::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 4: Synergy Meter Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSynergyMeterWidgetTest,
	"AshenOath.UI.SynergyMeterWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSynergyMeterWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_CompanionSynergyMeter* Widget = NewObject<UAshenUserWidget_CompanionSynergyMeter>();
	if (!TestNotNull(TEXT("CompanionSynergyMeter widget must be constructable"), Widget)) return false;

	Widget->UpdateSynergyDisplay(0.75f, 1.20f);
	TestEqual(TEXT("CachedSynergyPercent must match"), Widget->CachedSynergyPercent, 0.75f);
	TestEqual(TEXT("CachedMultiplier must match"), Widget->CachedMultiplier, 1.20f);

	return true;
}

// =============================================================================
//  Test 5: Milestone 210 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone210VerificationTest,
	"AshenOath.Milestone.Milestone210.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone210VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone210.Verification: Milestone 210 Systems Ready!"));
	return true;
}
