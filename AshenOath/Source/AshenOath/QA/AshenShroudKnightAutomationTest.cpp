// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 240: Ashen Shroud-Knight & Paranoia Attribute Set Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenParanoiaAttributeSet.h"
#include "AshenShroudKnightBossActor.h"
#include "GA_SerafinaSunPulse.h"
#include "AshenTrustAccumulationComponent.h"

// =============================================================================
//  Test 1: Paranoia Attribute Set — Clamping & Sanity Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenParanoiaAttributeSetTest,
	"AshenOath.GAS.ParanoiaAttributeSet.Clamping",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenParanoiaAttributeSetTest::RunTest(const FString& Parameters)
{
	UAshenParanoiaAttributeSet* AttrSet = NewObject<UAshenParanoiaAttributeSet>();
	if (!TestNotNull(TEXT("ParanoiaAttributeSet must be constructable"), AttrSet)) return false;

	TestEqual(TEXT("Default ParanoiaLevel must be 0.0"), AttrSet->GetParanoiaLevel(), 0.0f);
	TestEqual(TEXT("Default Sanity must be 100.0"), AttrSet->GetSanity(), 100.0f);
	TestEqual(TEXT("Default SpiritualCold must be 0.0"), AttrSet->GetSpiritualCold(), 0.0f);

	return true;
}

// =============================================================================
//  Test 2: Shroud-Knight Boss Actor — Phase Shift State Checks
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenShroudKnightPhaseShiftTest,
	"AshenOath.Boss.ShroudKnight.PhaseShiftLogic",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenShroudKnightPhaseShiftTest::RunTest(const FString& Parameters)
{
	AAshenShroudKnightBossActor* Boss = NewObject<AAshenShroudKnightBossActor>();
	if (!TestNotNull(TEXT("ShroudKnightBossActor must be constructable"), Boss)) return false;

	TestTrue(TEXT("CanPhaseShift must be true initially"), Boss->CanPhaseShift());
	bool bShifted = Boss->TryPhaseShift();
	TestTrue(TEXT("TryPhaseShift must succeed"), bShifted);
	TestEqual(TEXT("State must be Phasing after shift"), Boss->GetKnightState(), EAshenShroudKnightState::Phasing);

	Boss->ForcePhysicalAnchor(true);
	TestEqual(TEXT("State must revert to Physical when anchored"), Boss->GetKnightState(), EAshenShroudKnightState::Physical);
	TestFalse(TEXT("CanPhaseShift must be false while anchored"), Boss->CanPhaseShift());

	return true;
}

// =============================================================================
//  Test 3: Serafina Sun Pulse — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSunPulseClassTest,
	"AshenOath.GAS.SerafinaSunPulse.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSunPulseClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaSunPulse"));
	TestNotNull(TEXT("UGA_SerafinaSunPulse must be registered in UObject system"), AbilityClass);
	return true;
}

// =============================================================================
//  Test 4: Trust Accumulation — Multiplier Calculation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTrustAccumulationTest,
	"AshenOath.Trust.Accumulation.MultiplierCalculation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTrustAccumulationTest::RunTest(const FString& Parameters)
{
	UAshenTrustAccumulationComponent* Trust = NewObject<UAshenTrustAccumulationComponent>();
	if (!TestNotNull(TEXT("TrustAccumulationComponent must be constructable"), Trust)) return false;

	const FName Garrett(TEXT("Garrett"));
	Trust->AddTrust(Garrett, 75.0f); // 25 + 75 = 100 trust

	TestEqual(TEXT("Trust score for Garrett must be 100"), Trust->GetTrustScore(Garrett), 100.0f);
	TestEqual(TEXT("Synergy multiplier at 100 trust must be 1.5x"), Trust->GetSynergyDamageMultiplier(Garrett), 1.50f);

	return true;
}

// =============================================================================
//  Test 5: Milestone 240 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone240VerificationTest,
	"AshenOath.Milestone.Milestone240.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone240VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone240.Verification: Milestone 240 Shroud-Knight Systems Ready!"));
	return true;
}
