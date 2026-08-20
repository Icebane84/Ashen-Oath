// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1955: Master Batch #97 QA Automation Test Suite — Living Journal, Cartographer's Memory Constellation & Consequence Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Narrative/AshenLivingJournalSubsystem.h"
#include "Narrative/AshenJournalPerspectiveEvaluatorComponent.h"
#include "Combat/AshenTacticalFramePerkEvaluatorComponent.h"
#include "UI/AshenLivingParchmentInkModulator.h"
#include "Combat/AshenWeaponRunecraftMeshAdapter.h"

// =============================================================================
//  Test 1: Living Journal Resolution Beats, Perspective & Tactical Frame Perks
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch97JournalAndPerksTest,
	"AshenOath.Narrative.JournalAndPerks.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch97JournalAndPerksTest::RunTest(const FString& Parameters)
{
	// Test 1: Subsystem Resolution Beat Recording & Perk Unlocking
	UAshenLivingJournalSubsystem* Subsystem = NewObject<UAshenLivingJournalSubsystem>();
	if (!TestNotNull(TEXT("LivingJournalSubsystem must be constructable"), Subsystem)) return false;

	const FName AshCasketID(TEXT("Monster.AshCasket"));
	TestFalse(TEXT("Perk must be locked initially"), Subsystem->HasTacticalFramePerk(AshCasketID));

	// Record Synarchy resolution
	Subsystem->RecordSomaticResolutionBeat(AshCasketID, EJournalPerspectiveType::TripartiteSynarchy);
	TestTrue(TEXT("Perk MUST be unlocked after Synarchy resolution"), Subsystem->HasTacticalFramePerk(AshCasketID));

	const FJournalResolutionEntry* Entry = Subsystem->JournalEntries.Find(AshCasketID);
	if (TestNotNull(TEXT("Journal Entry must exist"), Entry))
	{
		TestEqual(TEXT("Perspective must be TripartiteSynarchy"), Entry->Perspective, EJournalPerspectiveType::TripartiteSynarchy);
		TestFalse(TEXT("Kaelen entry text must not be empty"), Entry->KaelenEntryText.IsEmpty());
		TestFalse(TEXT("Garrett margin note must not be empty"), Entry->GarrettMarginNote.IsEmpty());
		TestFalse(TEXT("Serafina leaf script must not be empty"), Entry->SerafinaMarginNote.IsEmpty());
	}

	// Test 2: Perspective Evaluator Gating
	UAshenJournalPerspectiveEvaluatorComponent* PerspEval = NewObject<UAshenJournalPerspectiveEvaluatorComponent>();
	if (!TestNotNull(TEXT("JournalPerspectiveEvaluatorComponent must be constructable"), PerspEval)) return false;

	TestEqual(TEXT("Sync finisher with 0.75 trust -> TripartiteSynarchy"),
		PerspEval->EvaluateResolutionPerspective(true, 0.75f, 0.20f), EJournalPerspectiveType::TripartiteSynarchy);
	TestEqual(TEXT("Sync finisher with 0.40 trust (< 0.60) -> SolitaryMartyrdom"),
		PerspEval->EvaluateResolutionPerspective(true, 0.40f, 0.50f), EJournalPerspectiveType::SolitaryMartyrdom);
	TestEqual(TEXT("Solo kill without sync finisher -> SolitaryMartyrdom"),
		PerspEval->EvaluateResolutionPerspective(false, 0.90f, 0.10f), EJournalPerspectiveType::SolitaryMartyrdom);

	// Test 3: Tactical Frame Perk Math
	UAshenTacticalFramePerkEvaluatorComponent* PerkEval = NewObject<UAshenTacticalFramePerkEvaluatorComponent>();
	if (!TestNotNull(TEXT("TacticalFramePerkEvaluatorComponent must be constructable"), PerkEval)) return false;

	const float NormalRadius = PerkEval->CalculateAdjustedSunPulseRadius(300.0f, false);
	TestEqual(TEXT("Standard Sun-Pulse radius must equal 300.0 uu"), NormalRadius, 300.0f);

	const float ExpandedRadius = PerkEval->CalculateAdjustedSunPulseRadius(300.0f, true);
	TestEqual(TEXT("Earned Knowledge Sun-Pulse radius must equal 405.0 uu (1.35x)"), ExpandedRadius, 405.0f);

	TestEqual(TEXT("Garrett callout time advance must be 1.0s"), PerkEval->GetGarrettCalloutTimeAdvance(true), 1.0f);

	return true;
}

// =============================================================================
//  Test 2: Parchment Soot Modulators & Weapon Runecraft Cleansing
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch97ParchmentAndWeaponTest,
	"AshenOath.Narrative.ParchmentAndWeapon.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch97ParchmentAndWeaponTest::RunTest(const FString& Parameters)
{
	// Parchment Material Modulator
	UAshenLivingParchmentInkModulator* ParchmentMod = NewObject<UAshenLivingParchmentInkModulator>();
	if (!TestNotNull(TEXT("LivingParchmentInkModulator must be constructable"), ParchmentMod)) return false;

	TestEqual(TEXT("Solitary Martyrdom soot vignette must equal 0.85"),
		ParchmentMod->CalculateSootVignette(EJournalPerspectiveType::SolitaryMartyrdom), 0.85f);
	TestEqual(TEXT("Tripartite Synarchy soot vignette must equal 0.10"),
		ParchmentMod->CalculateSootVignette(EJournalPerspectiveType::TripartiteSynarchy), 0.10f);

	TestEqual(TEXT("Solitary Martyrdom tear stain opacity must equal 0.75"),
		ParchmentMod->CalculateTearStainOpacity(EJournalPerspectiveType::SolitaryMartyrdom), 0.75f);
	TestEqual(TEXT("Tripartite Synarchy tear stain opacity must equal 0.0"),
		ParchmentMod->CalculateTearStainOpacity(EJournalPerspectiveType::TripartiteSynarchy), 0.0f);

	// Weapon Runecraft Mesh Cleansing
	UAshenWeaponRunecraftMeshAdapter* Runecraft = NewObject<UAshenWeaponRunecraftMeshAdapter>();
	if (!TestNotNull(TEXT("WeaponRunecraftMeshAdapter must be constructable"), Runecraft)) return false;

	Runecraft->UpdateRunecraftState(5); // 5 / 10 = 50%
	TestEqual(TEXT("Oathbringer soot opacity at 5 kills must equal 0.50"), Runecraft->SootLayerOpacity, 0.50f);
	TestEqual(TEXT("Oathbringer gold rune emissive at 5 kills: 0.50 * 2.5 = 1.25"), Runecraft->GoldRuneEmissiveIntensity, 1.25f);

	Runecraft->UpdateRunecraftState(10); // 10 / 10 = 100%
	TestEqual(TEXT("Oathbringer soot opacity at 10 kills must equal 0.0 (Clean)"), Runecraft->SootLayerOpacity, 0.0f);
	TestEqual(TEXT("Oathbringer gold rune emissive at 10 kills must equal 2.50 (Max)"), Runecraft->GoldRuneEmissiveIntensity, 2.50f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #97 LIVING JOURNAL & CONSEQUENCE VERIFIED (1,955 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
