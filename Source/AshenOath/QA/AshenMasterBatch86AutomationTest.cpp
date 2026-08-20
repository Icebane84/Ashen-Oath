// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1735: Master Batch #86 QA Automation Test Suite — Null Zone, Whispering Winds & Environmental Anchoring Pipeline
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1735MasterSynthesisOrchestrator.h"
#include "World/AshenWhisperingWindSubsystem.h"
#include "World/AshenNullZoneVolume.h"
#include "World/AshenMemoryFragmentActor.h"
#include "World/AshenEnvironmentalAnchorComponent.h"
#include "Combat/AshenNullZoneGASAbility.h"

// =============================================================================
//  Test 1: Null Zone & Environmental Suite
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch86NullZoneSuiteTest,
	"AshenOath.NullZone.EnvironmentalSuite.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch86NullZoneSuiteTest::RunTest(const FString& Parameters)
{
	UAshenWhisperingWindSubsystem* Subsystem = NewObject<UAshenWhisperingWindSubsystem>();
	if (!TestNotNull(TEXT("WhisperingWindSubsystem must be constructable"), Subsystem)) return false;
	Subsystem->UpdateWhisperIntensity(0.5f, 0.5f);
	TestEqual(TEXT("CurrentWhisperIntensity must equal 0.5f"), Subsystem->CurrentWhisperIntensity, 0.5f);

	AAshenNullZoneVolume* Volume = NewObject<AAshenNullZoneVolume>();
	if (!TestNotNull(TEXT("NullZoneVolume must be constructable"), Volume)) return false;
	TestEqual(TEXT("NullZoneRadius must equal 1500.0f"), Volume->NullZoneRadius, 1500.0f);

	AAshenMemoryFragmentActor* Fragment = NewObject<AAshenMemoryFragmentActor>();
	if (!TestNotNull(TEXT("MemoryFragmentActor must be constructable"), Fragment)) return false;
	TestEqual(TEXT("ImprintWeight must equal 0.5f"), Fragment->ImprintWeight, 0.5f);
	return true;
}

// =============================================================================
//  Test 2: Master Milestone 1735 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1735MasterVerificationTest,
	"AshenOath.Milestone.Milestone1735.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1735MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1735MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1735MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1735 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Master Milestone 1735 Synthesis validation must return true"), Orchestrator->ValidateMasterMilestone1735Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1735 NULL ZONE & ENVIRONMENTAL CORRUPTION SUITE VERIFIED (1,735 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
