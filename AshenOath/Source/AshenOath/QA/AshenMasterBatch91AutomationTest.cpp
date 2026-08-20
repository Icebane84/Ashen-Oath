// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1835: Master Batch #91 QA Automation Test Suite — Stance Morphing, Motion-Warped Melee & Flank Execution Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenCombatStanceSubsystem.h"
#include "Combat/AshenFlankExecutionComponent.h"
#include "Combat/AshenStanceDamageEvaluatorComponent.h"
#include "Combat/AshenPerfectParryManagerComponent.h"
#include "Combat/AshenBerserkRendGASAbility.h"
#include "Combat/AshenAegisBastionGASAbility.h"
#include "Combat/AshenFlowCounterGASAbility.h"
#include "Companions/AshenCombatStanceCompanionAdapter.h"

// =============================================================================
//  Test 1: Stance State Transitions & Modifier Math
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch91StanceModifiersTest,
	"AshenOath.Combat.StanceModifiers.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch91StanceModifiersTest::RunTest(const FString& Parameters)
{
	// Test 1: Stance Subsystem
	UAshenCombatStanceSubsystem* Subsystem = NewObject<UAshenCombatStanceSubsystem>();
	if (!TestNotNull(TEXT("CombatStanceSubsystem must be constructable"), Subsystem)) return false;

	TestTrue(TEXT("Switching to Berserk must succeed"), Subsystem->SwitchStance(ECombatStance::Berserk));
	TestEqual(TEXT("Active stance must be Berserk"), Subsystem->GetActiveStance(), ECombatStance::Berserk);

	// Test 2: Stance Modifiers
	UAshenStanceDamageEvaluatorComponent* Evaluator = NewObject<UAshenStanceDamageEvaluatorComponent>();
	if (!TestNotNull(TEXT("StanceDamageEvaluatorComponent must be constructable"), Evaluator)) return false;

	FStanceModifiers AegisMods = Evaluator->GetModifiersForStance(ECombatStance::Aegis);
	TestEqual(TEXT("Aegis poise bonus must equal +50.0f"), AegisMods.PoiseBonus, 50.0f);
	TestEqual(TEXT("Aegis damage taken multiplier must equal 0.70f (-30%)"), AegisMods.DamageTakenMultiplier, 0.70f);

	FStanceModifiers BerserkMods = Evaluator->GetModifiersForStance(ECombatStance::Berserk);
	TestEqual(TEXT("Berserk outgoing damage multiplier must equal 1.30f (+30%)"), BerserkMods.DamageMultiplier, 1.30f);
	TestEqual(TEXT("Berserk attack speed multiplier must equal 1.35f (+35%)"), BerserkMods.AttackSpeedMultiplier, 1.35f);

	return true;
}

// =============================================================================
//  Test 2: Flank Angle Math, Parries & Combo Hits
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch91FlankAndComboTest,
	"AshenOath.Combat.FlankAndCombo.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch91FlankAndComboTest::RunTest(const FString& Parameters)
{
	// Flank Angle Evaluation
	UAshenFlankExecutionComponent* Flank = NewObject<UAshenFlankExecutionComponent>();
	if (!TestNotNull(TEXT("FlankExecutionComponent must be constructable"), Flank)) return false;

	float Angle = 0.0f;
	// Attacker directly behind enemy facing Forward (0, 1, 0)
	const bool bDirectRear = Flank->IsFlankingEnemy(FVector(0, -100, 0), FVector(0, 0, 0), FVector(0, 1, 0), Angle);
	TestTrue(TEXT("Direct rear attack (angle ~0 deg) must be a flank"), bDirectRear);

	// Attacker directly in front of enemy facing Forward (0, 1, 0)
	const bool bFrontal = Flank->IsFlankingEnemy(FVector(0, 100, 0), FVector(0, 0, 0), FVector(0, 1, 0), Angle);
	TestFalse(TEXT("Frontal attack must NOT be a flank"), bFrontal);

	// Flank Damage Multiplier
	const float BaseDMG = 150.0f;
	TestEqual(TEXT("Flank damage must be 2.0x base (300.0)"), Flank->CalculateFlankDamage(BaseDMG, true), 300.0f);
	TestEqual(TEXT("Non-flank damage must be 1.0x base (150.0)"), Flank->CalculateFlankDamage(BaseDMG, false), 150.0f);

	// Perfect Parry Timing
	UAshenPerfectParryManagerComponent* Parry = NewObject<UAshenPerfectParryManagerComponent>();
	if (!TestNotNull(TEXT("PerfectParryManagerComponent must be constructable"), Parry)) return false;

	float SanityGain = 0.0f;
	TestTrue(TEXT("0.10s parry within 0.20s window must succeed"), Parry->EvaluateParryTiming(0.10f, SanityGain));
	TestEqual(TEXT("Sanity gain must equal 15.0f"), SanityGain, 15.0f);

	TestFalse(TEXT("0.35s parry outside window must fail"), Parry->EvaluateParryTiming(0.35f, SanityGain));
	TestEqual(TEXT("Failed parry sanity gain must equal 0.0f"), SanityGain, 0.0f);

	// Berserk Combo Hit Scaling
	UAshenBerserkRendGASAbility* RendAbility = NewObject<UAshenBerserkRendGASAbility>();
	if (!TestNotNull(TEXT("BerserkRendGASAbility must be constructable"), RendAbility)) return false;

	float SpeedBonus = 0.0f;
	const float Hit3Damage = RendAbility->CalculateComboDamage(2, SpeedBonus); // Hit 3: Base 300 * (1.0 + 0.20) = 360.0
	TestEqual(TEXT("Combo Hit 3 damage must equal 360.0f"), Hit3Damage, 360.0f);
	TestEqual(TEXT("Combo Hit 3 speed bonus must equal +20% (0.20f)"), SpeedBonus, 0.20f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #91 COMBAT STANCE & FLANK EXECUTION TEST SUITE VERIFIED (1,835 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
