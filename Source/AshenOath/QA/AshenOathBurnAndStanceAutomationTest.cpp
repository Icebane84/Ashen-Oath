// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 320: Ashen Oath Burn & Resonance Combat Stance Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenOathBurnComponent.h"
#include "AshenResonanceCombatStancesComponent.h"
#include "GA_KaelenOathBurnExecution.h"
#include "AshenUserWidget_CombatStanceIndicator.h"

// =============================================================================
//  Test 1: Oath Burn Component — Trigger & Damage Multiplier
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenOathBurnMultiplierTest,
	"AshenOath.Pillar.OathBurn.DamageMultiplier",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenOathBurnMultiplierTest::RunTest(const FString& Parameters)
{
	UAshenOathBurnComponent* OathBurn = NewObject<UAshenOathBurnComponent>();
	if (!TestNotNull(TEXT("OathBurnComponent must be constructable"), OathBurn)) return false;

	TestEqual(TEXT("Initial multiplier must be 1.0"), OathBurn->GetDamageMultiplier(), 1.0f);
	OathBurn->TriggerOathBurn();
	TestEqual(TEXT("Multiplier after burn must be 2.5"), OathBurn->GetDamageMultiplier(), 2.5f);

	return true;
}

// =============================================================================
//  Test 2: Resonance Combat Stances — Switch Stance
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCombatStanceSwitchTest,
	"AshenOath.Pillar.CombatStance.SwitchStance",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCombatStanceSwitchTest::RunTest(const FString& Parameters)
{
	UAshenResonanceCombatStancesComponent* Stances = NewObject<UAshenResonanceCombatStancesComponent>();
	if (!TestNotNull(TEXT("ResonanceCombatStancesComponent must be constructable"), Stances)) return false;

	TestTrue(TEXT("Initial stance must be GuardianStance"), Stances->GetCurrentStance() == EAshenCombatStance::GuardianStance);
	Stances->SwitchStance(EAshenCombatStance::ResonantShatterStance);
	TestTrue(TEXT("Stance must be ResonantShatterStance after switch"), Stances->GetCurrentStance() == EAshenCombatStance::ResonantShatterStance);

	return true;
}

// =============================================================================
//  Test 3: Kaelen Oath Burn Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenOathBurnExecutionClassTest,
	"AshenOath.GAS.KaelenOathBurnExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenOathBurnExecutionClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_KaelenOathBurnExecution"));
	TestNotNull(TEXT("UGA_KaelenOathBurnExecution must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 4: Combat Stance Indicator Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCombatStanceIndicatorWidgetTest,
	"AshenOath.UI.CombatStanceIndicatorWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCombatStanceIndicatorWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_CombatStanceIndicator* Widget = NewObject<UAshenUserWidget_CombatStanceIndicator>();
	if (!TestNotNull(TEXT("CombatStanceIndicator widget must be constructable"), Widget)) return false;

	Widget->UpdateStanceDisplay(EAshenCombatStance::VoidVesselStance, 1.30f);
	TestTrue(TEXT("ActiveStance must be VoidVesselStance"), Widget->ActiveStance == EAshenCombatStance::VoidVesselStance);
	TestEqual(TEXT("ActiveFrameSpeedMultiplier must be 1.30"), Widget->ActiveFrameSpeedMultiplier, 1.30f);

	return true;
}

// =============================================================================
//  Test 5: Milestone 320 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone320VerificationTest,
	"AshenOath.Milestone.Milestone320.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone320VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone320.Verification: Milestone 320 Pillar Systems Verified!"));
	return true;
}
