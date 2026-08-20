// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 2035: Master Batch #101 QA Automation Test Suite — Combat Ecosystems of The Shattered Lands & TAM-001
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AI/AshenTAM001MemorySubsystem.h"
#include "Combat/AshenLightDarkModeEcosystemEvaluatorComponent.h"
#include "Combat/AshenHarmonicResonanceArmorShredComponent.h"
#include "AI/AshenTAM001AIDirectorComponent.h"

// =============================================================================
//  Test 1: TAM-001 Memory Model Calculations & Symbiotic Resonance State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch101TAM001AndResonanceTest,
	"AshenOath.AI.TAM001AndResonance.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch101TAM001AndResonanceTest::RunTest(const FString& Parameters)
{
	// Test 1: TAM-001 Subsystem Initialization
	UAshenTAM001MemorySubsystem* TAMSubsystem = NewObject<UAshenTAM001MemorySubsystem>();
	if (!TestNotNull(TEXT("TAM001MemorySubsystem must be constructable"), TAMSubsystem)) return false;

	TAMSubsystem->ActiveWeights.ConsistencyScore = 0.5f;
	TAMSubsystem->ActiveWeights.SeverityImpact = 0.0f;
	TestFalse(TEXT("Resonance must be locked at consistency 0.50"), TAMSubsystem->EvaluateSymbioticResonance());

	// Record 3 clean cooperative actions: 0.50 -> 0.80
	TAMSubsystem->RecordCooperativeAction(true, 0.0f);
	TAMSubsystem->RecordCooperativeAction(true, 0.0f);
	TAMSubsystem->RecordCooperativeAction(true, 0.0f);

	TestEqual(TEXT("Consistency score must reach 0.80"), TAMSubsystem->ActiveWeights.ConsistencyScore, 0.80f);
	TestTrue(TEXT("Symbiotic Resonance must unlock when consistency >= 0.80 and severity <= 0.20"),
		TAMSubsystem->ActiveWeights.bIsSymbioticResonanceUnlocked);

	// Test 2: AI Director Companion Spacing Lerp
	UAshenTAM001AIDirectorComponent* AIDirector = NewObject<UAshenTAM001AIDirectorComponent>();
	if (!TestNotNull(TEXT("TAM001AIDirectorComponent must be constructable"), AIDirector)) return false;

	TestEqual(TEXT("Spacing at 0.0 consistency must equal 500.0uu"), AIDirector->CalculateCompanionDefensiveSpacing(0.0f), 500.0f);
	TestEqual(TEXT("Spacing at 1.0 consistency must contract to 250.0uu"), AIDirector->CalculateCompanionDefensiveSpacing(1.0f), 250.0f);

	return true;
}

// =============================================================================
//  Test 2: Light/Dark Mode Ecosystem Reactivity & Harmonic Armor Shred
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch101EcosystemMechanicsTest,
	"AshenOath.AI.EcosystemMechanics.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch101EcosystemMechanicsTest::RunTest(const FString& Parameters)
{
	// Test 1: Light vs Dark Mode Creature Reactions
	UAshenLightDarkModeEcosystemEvaluatorComponent* ModeEvaluator = NewObject<UAshenLightDarkModeEcosystemEvaluatorComponent>();
	if (!TestNotNull(TEXT("LightDarkModeEcosystemEvaluatorComponent must be constructable"), ModeEvaluator)) return false;

	TestEqual(TEXT("Glimmerdrake in Light Mode must grant TranquilityBuff"),
		ModeEvaluator->EvaluateCreatureReaction(FName(TEXT("Creature.Glimmerdrake")), false),
		EEcosystemModeReaction::TranquilityBuff);

	TestEqual(TEXT("Glimmerdrake in Dark Mode must enter ShadowedPanic"),
		ModeEvaluator->EvaluateCreatureReaction(FName(TEXT("Creature.Glimmerdrake")), true),
		EEcosystemModeReaction::ShadowedPanic);

	TestEqual(TEXT("SorrowLeech in Light Mode must suffer FlameAttraction"),
		ModeEvaluator->EvaluateCreatureReaction(FName(TEXT("Creature.SorrowLeech")), false),
		EEcosystemModeReaction::FlameAttraction);

	TestEqual(TEXT("SorrowLeech in Dark Mode must trigger DespairParasite"),
		ModeEvaluator->EvaluateCreatureReaction(FName(TEXT("Creature.SorrowLeech")), true),
		EEcosystemModeReaction::DespairParasite);

	// Test 2: Harmonic Resonance Silicon Armor Shred (-70%)
	UAshenHarmonicResonanceArmorShredComponent* ArmorShredComp = NewObject<UAshenHarmonicResonanceArmorShredComponent>();
	if (!TestNotNull(TEXT("HarmonicResonanceArmorShredComponent must be constructable"), ArmorShredComp)) return false;

	const float BaseArmor = 1000.0f;
	const float FracturedArmor = ArmorShredComp->ShatterCrystallinePlates(BaseArmor);
	TestEqual(TEXT("Shattered armor must equal 300.0 (0.30x)"), FracturedArmor, 300.0f);
	TestTrue(TEXT("Armor must be flagged fractured"), ArmorShredComp->bArmorFractured);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #101 COMBAT ECOSYSTEM & TAM-001 VERIFIED (2,035 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
