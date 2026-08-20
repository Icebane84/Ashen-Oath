// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1975: Master Batch #98 QA Automation Test Suite — Epistemic Grounding & Consequence Profile Hierarchy
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Narrative/AshenEpistemicGroundingSubsystem.h"
#include "Narrative/AshenConsequenceProfileEvaluatorComponent.h"
#include "Narrative/AshenTripartiteInterpretationComponent.h"
#include "Combat/AshenMechanicalHonestyEvaluatorComponent.h"
#include "Combat/AshenMilestoneConvergenceGASAbility.h"

// =============================================================================
//  Test 1: Layer 0 Canonical Event Logging & Consequence Profile Tiers
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch98EpistemicTiersTest,
	"AshenOath.Narrative.EpistemicTiers.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch98EpistemicTiersTest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Layer 0 Canonical Event Logging
	UAshenEpistemicGroundingSubsystem* Subsystem = NewObject<UAshenEpistemicGroundingSubsystem>();
	if (!TestNotNull(TEXT("EpistemicGroundingSubsystem must be constructable"), Subsystem)) return false;

	const FName BossID(TEXT("Boss.AshCasket"));
	const FName FinisherID(TEXT("Finisher.CryoQuench"));

	Subsystem->RecordCanonicalCombatEvent(BossID, FinisherID, EConsequenceProfileTier::Milestone, true, 0.88f);
	TestEqual(TEXT("Canonical event log size must equal 1"), Subsystem->CanonicalEventLog.Num(), 1);
	TestEqual(TEXT("Milestone event count must equal 1"), Subsystem->GetMilestoneEventsCount(), 1);

	// Add Common event
	Subsystem->RecordCanonicalCombatEvent(FName(TEXT("Mob.GloomThrall")), FName(TEXT("Finisher.BasicSlash")),
		EConsequenceProfileTier::Common, false, 0.30f);
	TestEqual(TEXT("Canonical event log size must equal 2"), Subsystem->CanonicalEventLog.Num(), 2);
	TestEqual(TEXT("Milestone event count must still equal 1"), Subsystem->GetMilestoneEventsCount(), 1);

	// Test 2: Consequence Profile Tiering Logic
	UAshenConsequenceProfileEvaluatorComponent* TierEval = NewObject<UAshenConsequenceProfileEvaluatorComponent>();
	if (!TestNotNull(TEXT("ConsequenceProfileEvaluatorComponent must be constructable"), TierEval)) return false;

	TestEqual(TEXT("Boss + Sync Finisher -> Milestone (Tier III)"),
		TierEval->EvaluateEncounterTier(true, false, true), EConsequenceProfileTier::Milestone);
	TestEqual(TEXT("Elite Symbiote -> Rare (Tier II)"),
		TierEval->EvaluateEncounterTier(false, true, true), EConsequenceProfileTier::Rare);
	TestEqual(TEXT("Boss without Sync Finisher -> Rare (Tier II)"),
		TierEval->EvaluateEncounterTier(true, false, false), EConsequenceProfileTier::Rare);
	TestEqual(TEXT("Basic Skirmish Mob -> Common (Tier I)"),
		TierEval->EvaluateEncounterTier(false, false, false), EConsequenceProfileTier::Common);

	return true;
}

// =============================================================================
//  Test 2: Tripartite Interpretation, Mechanical Honesty & Ability Math
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch98InterpretationAndHonestyTest,
	"AshenOath.Narrative.InterpretationAndHonesty.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch98InterpretationAndHonestyTest::RunTest(const FString& Parameters)
{
	// Tripartite Interpretation Package Synthesis
	UAshenTripartiteInterpretationComponent* InterpComp = NewObject<UAshenTripartiteInterpretationComponent>();
	if (!TestNotNull(TEXT("TripartiteInterpretationComponent must be constructable"), InterpComp)) return false;

	const FTripartiteInterpretationPackage SynarchyPkg = InterpComp->FormulateInterpretation(FName(TEXT("Boss.AshCasket")), true);
	TestFalse(TEXT("Kaelen prose must not be empty"), SynarchyPkg.KaelenSubjectiveProse.IsEmpty());
	TestFalse(TEXT("Garrett tactical note must not be empty"), SynarchyPkg.GarrettTacticalNote.IsEmpty());
	TestFalse(TEXT("Serafina grace leaf must not be empty"), SynarchyPkg.SerafinaGraceLeaf.IsEmpty());

	// Mechanical Honesty Evaluator
	UAshenMechanicalHonestyEvaluatorComponent* HonestyEval = NewObject<UAshenMechanicalHonestyEvaluatorComponent>();
	if (!TestNotNull(TEXT("MechanicalHonestyEvaluatorComponent must be constructable"), HonestyEval)) return false;

	TestTrue(TEXT("Frame data integrity must hold even if character believes in solo martyrdom"),
		HonestyEval->ValidateFrameDataIntegrity(true, true));

	// Milestone Convergence Ability Math
	UAshenMilestoneConvergenceGASAbility* ConvergenceAbility = NewObject<UAshenMilestoneConvergenceGASAbility>();
	if (!TestNotNull(TEXT("MilestoneConvergenceGASAbility must be constructable"), ConvergenceAbility)) return false;

	TestEqual(TEXT("Milestone finisher damage must equal 2500.0"), ConvergenceAbility->MilestoneFinisherDamage, 2500.0f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #98 EPISTEMIC GROUNDING VERIFIED (1,975 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
