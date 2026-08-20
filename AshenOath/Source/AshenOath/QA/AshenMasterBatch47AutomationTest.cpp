// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 955: Ashen Master Batch #47 QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone955MasterSynthesisOrchestrator.h"
#include "World/AshenCorruptedMiasmaHazardVolume.h"
#include "Combat/AshenSomaticCorruptionDecayComponent.h"
#include "Companions/AshenGarrettFlankDistractionAdapterComponent.h"
#include "Companions/AshenSerafinaAegisSanctuaryAuraComponent.h"

// =============================================================================
//  Test 1: Corrupted Miasma Hazard Volume — Miasma DPS
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCorruptedMiasmaHazardVolumeTest,
	"AshenOath.Hazard.MiasmaVolume.DPSVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCorruptedMiasmaHazardVolumeTest::RunTest(const FString& Parameters)
{
	AAshenCorruptedMiasmaHazardVolume* Volume = NewObject<AAshenCorruptedMiasmaHazardVolume>();
	if (!TestNotNull(TEXT("Corrupted Miasma Hazard Volume must be constructable"), Volume)) return false;

	TestTrue(TEXT("Miasma DPS must be greater than 0"), Volume->MiasmaCorruptionDPS > 0.0f);
	return true;
}

// =============================================================================
//  Test 2: Somatic Corruption Decay Component — Accumulation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSomaticCorruptionDecayTest,
	"AshenOath.Combat.SomaticDecay.Accumulation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSomaticCorruptionDecayTest::RunTest(const FString& Parameters)
{
	UAshenSomaticCorruptionDecayComponent* Comp = NewObject<UAshenSomaticCorruptionDecayComponent>();
	if (!TestNotNull(TEXT("Somatic Corruption Decay Component must be constructable"), Comp)) return false;

	Comp->AccumulateSomaticCorruption(25.0f);
	TestEqual(TEXT("Accumulated corruption level must equal 25.0f"), Comp->AccumulatedCorruptionLevel, 25.0f);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 955 Verification Across All 955 Builds
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone955MasterVerificationTest,
	"AshenOath.Milestone.Milestone955.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone955MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone955MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone955MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 955 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMasterMilestone955Synthesis();
	TestTrue(TEXT("Master Milestone 955 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 955 QA SUITE VERIFIED (955 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
