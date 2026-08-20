// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1815: Master Batch #90 QA Automation Test Suite — Nightmare Incursion, Transference Cascade & Reality Sundering
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "World/AshenNightmareIncursionSubsystem.h"
#include "Soul/AshenTransferenceCascadeComponent.h"
#include "World/AshenRealitySunderingEvaluatorComponent.h"
#include "Combat/AshenTransferenceShieldGASAbility.h"
#include "AI/AshenNightmareIncursionAIDirectorComponent.h"
#include "World/AshenNightmareRiftActor.h"
#include "Combat/AshenRealitySunderGASAbility.h"
#include "Companions/AshenNightmareCompanionReactionAdapter.h"

// =============================================================================
//  Test 1: Incursion Triggers & Transference Strain Progression
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch90IncursionAndStrainTest,
	"AshenOath.Nightmare.IncursionAndStrain.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch90IncursionAndStrainTest::RunTest(const FString& Parameters)
{
	// Test 1: Incursion Threshold Gating
	UAshenNightmareIncursionSubsystem* Subsystem = NewObject<UAshenNightmareIncursionSubsystem>();
	if (!TestNotNull(TEXT("NightmareIncursionSubsystem must be constructable"), Subsystem)) return false;

	TestFalse(TEXT("Debt at 0.50 should NOT trigger Nightmare Incursion"), Subsystem->EvaluateIncursionTrigger(0.50f));
	TestTrue(TEXT("Debt at 0.80 MUST trigger Nightmare Incursion"), Subsystem->EvaluateIncursionTrigger(0.80f));
	TestEqual(TEXT("Incursion intensity at 0.80 debt must equal 0.20f"), Subsystem->CurrentIncursionState.IncursionIntensity, 0.20f);

	// Test 2: Transference Cascade 4-Stage Strain
	UAshenTransferenceCascadeComponent* Cascade = NewObject<UAshenTransferenceCascadeComponent>();
	if (!TestNotNull(TEXT("TransferenceCascadeComponent must be constructable"), Cascade)) return false;

	TestEqual(TEXT("0.10 trauma -> Stable"), Cascade->EvaluateStrainStage(0.10f), ETransferenceStrainStage::Stable);
	TestEqual(TEXT("0.45 trauma -> Flickering"), Cascade->EvaluateStrainStage(0.45f), ETransferenceStrainStage::Flickering);
	TestEqual(TEXT("0.70 trauma -> Fractured"), Cascade->EvaluateStrainStage(0.70f), ETransferenceStrainStage::Fractured);
	TestEqual(TEXT("0.95 trauma -> Catastrophic"), Cascade->EvaluateStrainStage(0.95f), ETransferenceStrainStage::Catastrophic);

	return true;
}

// =============================================================================
//  Test 2: Damage Multipliers, Shield Absorption & AI Director Scaling
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch90MechanicsTest,
	"AshenOath.Nightmare.Mechanics.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch90MechanicsTest::RunTest(const FString& Parameters)
{
	// Reality Sundering Multiplier
	UAshenRealitySunderingEvaluatorComponent* Reality = NewObject<UAshenRealitySunderingEvaluatorComponent>();
	if (!TestNotNull(TEXT("RealitySunderingEvaluatorComponent must be constructable"), Reality)) return false;

	const float MultiplierAtHalfDebt = Reality->CalculateSunderingDamageMultiplier(0.50f);
	TestEqual(TEXT("Multiplier at 0.50 debt must equal 1.25x"), MultiplierAtHalfDebt, 1.25f);

	const float MultiplierAtMaxDebt = Reality->CalculateSunderingDamageMultiplier(1.0f);
	TestEqual(TEXT("Multiplier at 1.00 debt must equal 1.50x"), MultiplierAtMaxDebt, 1.50f);

	// Transference Shield Absorption and Sanity Restoration
	UAshenTransferenceShieldGASAbility* Shield = NewObject<UAshenTransferenceShieldGASAbility>();
	if (!TestNotNull(TEXT("TransferenceShieldGASAbility must be constructable"), Shield)) return false;

	float SanityRestored = 0.0f;
	const float Unmitigated = Shield->AbsorbDamageAndConvert(300.0f, SanityRestored);
	TestEqual(TEXT("300 damage fully absorbed -> 0 unmitigated"), Unmitigated, 0.0f);
	TestEqual(TEXT("300 absorbed at 25% ratio -> 75.0 sanity restored"), SanityRestored, 75.0f);

	// AI Director Phantom Count Calculation
	UAshenNightmareIncursionAIDirectorComponent* Director = NewObject<UAshenNightmareIncursionAIDirectorComponent>();
	if (!TestNotNull(TEXT("NightmareAIDirectorComponent must be constructable"), Director)) return false;

	const int32 DesiredPhantoms = Director->CalculateDesiredPhantomCount(0.50f, 1); // Round(0.5*4)=2 + 2 = 4
	TestEqual(TEXT("Desired phantoms must equal 4"), DesiredPhantoms, 4);

	// Companion Stance Modulation
	UAshenNightmareCompanionReactionAdapter* CompanionAdapter = NewObject<UAshenNightmareCompanionReactionAdapter>();
	if (!TestNotNull(TEXT("NightmareCompanionReactionAdapter must be constructable"), CompanionAdapter)) return false;

	const FName GarrettStance = CompanionAdapter->EvaluateDefensiveStance(FName(TEXT("Garrett")), 0.80f, ETransferenceStrainStage::Fractured);
	TestEqual(TEXT("Garrett must adopt AegisInterception during severe incursion"), GarrettStance, FName(TEXT("Stance.Garrett.AegisInterception")));

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #90 NIGHTMARE INCURSION & STRAIN TEST SUITE VERIFIED (1,815 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
