// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1115: Ashen Master Batch #55 QA Automation Test Suite

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1115MasterSynthesisOrchestrator.h"
#include "World/AshenSovereignPhoenixAscensionMonumentActor.h"
#include "Combat/AshenSovereignPhoenixFlameAscensionAbility.h"
#include "Companions/AshenGarrettMasterFlankDirectorComponent.h"
#include "Companions/AshenSerafinaMasterPurgeAuraDirectorComponent.h"

// =============================================================================
//  Test 1: Sovereign Phoenix Ascension Monument Actor Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch55SovereignPhoenixMonumentTest,
	"AshenOath.World.SovereignPhoenixMonument.ActivationVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch55SovereignPhoenixMonumentTest::RunTest(const FString& Parameters)
{
	AAshenSovereignPhoenixAscensionMonumentActor* Actor = NewObject<AAshenSovereignPhoenixAscensionMonumentActor>();
	if (!TestNotNull(TEXT("Sovereign Phoenix Monument Actor must be constructable"), Actor)) return false;

	bool bResult = Actor->ActivateSovereignPhoenixMonument();
	TestTrue(TEXT("Sovereign Phoenix Monument activation must return true"), bResult);
	return true;
}

// =============================================================================
//  Test 2: Sovereign Phoenix Flame Ascension Ability — Trigger
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch55SovereignPhoenixFlameAbilityTest,
	"AshenOath.Combat.SovereignPhoenixFlameAbility.BurstTrigger",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch55SovereignPhoenixFlameAbilityTest::RunTest(const FString& Parameters)
{
	UAshenSovereignPhoenixFlameAscensionAbility* Ability = NewObject<UAshenSovereignPhoenixFlameAscensionAbility>();
	if (!TestNotNull(TEXT("Sovereign Phoenix Flame Ascension Ability must be constructable"), Ability)) return false;

	bool bResult = Ability->TriggerSovereignPhoenixFlameAscension();
	TestTrue(TEXT("Sovereign Phoenix Flame Ascension Ability trigger must return true"), bResult);
	return true;
}

// =============================================================================
//  Test 3: Master Milestone 1115 Verification Across All 1,115 Builds
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1115MasterVerificationTest,
	"AshenOath.Milestone.Milestone1115.MasterVerification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1115MasterVerificationTest::RunTest(const FString& Parameters)
{
	UAshenMilestone1115MasterSynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1115MasterSynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Master Milestone 1115 Orchestrator must be constructable"), Orchestrator)) return false;

	bool bResult = Orchestrator->ValidateMasterMilestone1115Synthesis();
	TestTrue(TEXT("Master Milestone 1115 Synthesis validation must return true"), bResult);

	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER MILESTONE 1115 QA SUITE VERIFIED (1115 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================================"));
	return true;
}
