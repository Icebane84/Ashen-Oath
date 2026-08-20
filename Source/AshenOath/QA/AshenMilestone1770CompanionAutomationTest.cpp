// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1770: Companion Fatigue & Resonance Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1770SynthesisOrchestrator.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Companions/AshenCompanionDivergenceComponent.h"
#include "Companions/AshenResonanceAnchoringComponent.h"
#include "World/AshenCompanionVulnerabilityMarkerActor.h"
#include "Combat/AshenResonanceSyncGASAbility.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1770CompanionAutomationTest,
	"AshenOath.QA.Companion.Milestone1770Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1770CompanionAutomationTest::RunTest(const FString& Parameters)
{
	// Test 1: Fatigue Subsystem
	UAshenCompanionFatigueSubsystem* Subsystem = NewObject<UAshenCompanionFatigueSubsystem>();
	if (!TestNotNull(TEXT("CompanionFatigueSubsystem must be constructable"), Subsystem)) return false;
	Subsystem->AccumulateFatigue(FName(TEXT("Garrett")), 0.75f);
	TestTrue(TEXT("Garrett must be vulnerable at 0.75 fatigue"), Subsystem->IsCompanionVulnerable(FName(TEXT("Garrett"))));

	// Test 2: Divergence Component
	UAshenCompanionDivergenceComponent* Divergence = NewObject<UAshenCompanionDivergenceComponent>();
	if (!TestNotNull(TEXT("CompanionDivergenceComponent must be constructable"), Divergence)) return false;
	float Offset = Divergence->EvaluateNavigationOffset(FName(TEXT("Garrett")), 0.2f, true);
	TestEqual(TEXT("Garrett isolated offset must equal 800.0f"), Offset, 800.0f);

	// Test 3: Resonance Anchoring Component
	UAshenResonanceAnchoringComponent* Resonance = NewObject<UAshenResonanceAnchoringComponent>();
	if (!TestNotNull(TEXT("ResonanceAnchoringComponent must be constructable"), Resonance)) return false;
	TestTrue(TEXT("Balanced trust and low fatigue must activate resonance"),
		Resonance->EvaluateResonanceSync(0.8f, 0.85f, 0.2f, 0.2f, 0.7f));

	// Test 4: Vulnerability Marker Actor
	AAshenCompanionVulnerabilityMarkerActor* Marker = NewObject<AAshenCompanionVulnerabilityMarkerActor>();
	if (!TestNotNull(TEXT("CompanionVulnerabilityMarkerActor must be constructable"), Marker)) return false;

	// Test 5: Resonance Sync GAS Ability
	UAshenResonanceSyncGASAbility* Ability = NewObject<UAshenResonanceSyncGASAbility>();
	if (!TestNotNull(TEXT("ResonanceSyncGASAbility must be constructable"), Ability)) return false;
	TestEqual(TEXT("DamageMultiplierBonus must equal 0.15f"), Ability->DamageMultiplierBonus, 0.15f);

	UAshenMilestone1770SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1770SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1770 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1770 validation must return true"), Orchestrator->ValidateMilestone1770Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1770 COMPANION FATIGUE & RESONANCE SUITE VERIFIED ======"));
	return true;
}
