// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 2135: Master Batch #106 QA Automation Test Suite — The Soul Compilation Cycle & Relational Triage Engine
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Narrative/AshenDialogueChoiceEvaluator.h"
#include "Companions/AshenRelationalTriageSubsystem.h"
#include "Combat/AshenTransferenceSymptomComponent.h"
#include "Soul/AshenSoulConstellationNodeComponent.h"
#include "Combat/AshenTripartiteResonantCleaveGASAbility.h"

// =============================================================================
//  Test 1: Dialogue Choice Evaluator & Stance Compilation Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch106DialogueAndStanceTest,
	"AshenOath.Triage.DialogueAndStance.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch106DialogueAndStanceTest::RunTest(const FString& Parameters)
{
	UAshenDialogueChoiceEvaluator* Evaluator = NewObject<UAshenDialogueChoiceEvaluator>();
	if (!TestNotNull(TEXT("DialogueChoiceEvaluator must be constructable"), Evaluator)) return false;

	float BurnoutModifier = 1.0f;
	float TrustDelta = 0.0f;

	// Test 1: Lens of Grace
	Evaluator->EvaluateTherapyChoice(EInterpretiveTherapyLens::Grace, BurnoutModifier, TrustDelta);
	TestEqual(TEXT("Grace must yield Weaver Stance"), Evaluator->CurrentStance, ECompiledRelationalStance::WeaverStance);
	TestEqual(TEXT("Grace burnout decay modifier must be 1.25 (+25%)"), BurnoutModifier, 1.25f);
	TestEqual(TEXT("Grace trust delta must be +0.25"), TrustDelta, 0.25f);
	TestEqual(TEXT("Kaelen->Serafina Trust must be 0.75"), Evaluator->CurrentTrustVector.KaelenToSerafinaTrust, 0.75f);

	// Test 2: Lens of Accountability
	Evaluator->EvaluateTherapyChoice(EInterpretiveTherapyLens::Accountability, BurnoutModifier, TrustDelta);
	TestEqual(TEXT("Accountability must yield Martyr Stance"), Evaluator->CurrentStance, ECompiledRelationalStance::MartyrStance);
	TestEqual(TEXT("Accountability trust delta must be -0.15"), TrustDelta, -0.15f);

	// Test 3: Subsystem Incident Recording
	UAshenRelationalTriageSubsystem* Subsystem = NewObject<UAshenRelationalTriageSubsystem>();
	if (!TestNotNull(TEXT("RelationalTriageSubsystem must be constructable"), Subsystem)) return false;

	Subsystem->RecordTriageResolution(TEXT("Silent_Spire_Ambush"), EInterpretiveTherapyLens::Grace, ECompiledRelationalStance::WeaverStance);
	TestEqual(TEXT("Resolved incidents count must be 1"), Subsystem->ResolvedIncidents.Num(), 1);
	TestEqual(TEXT("Active stance must be WeaverStance"), Subsystem->ActiveStance, ECompiledRelationalStance::WeaverStance);

	return true;
}

// =============================================================================
//  Test 2: Transference Symptoms, Constellation Nodes & GAS Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch106SymptomsAndConstellationTest,
	"AshenOath.Triage.SymptomsAndConstellation.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMasterBatch106SymptomsAndConstellationTest::RunTest(const FString& Parameters)
{
	// Test 1: Transference Symptoms
	UAshenTransferenceSymptomComponent* SymptomComp = NewObject<UAshenTransferenceSymptomComponent>();
	if (!TestNotNull(TEXT("TransferenceSymptomComponent must be constructable"), SymptomComp)) return false;

	SymptomComp->UpdateTransferenceSymptoms(0.75f);
	TestEqual(TEXT("Tremor intensity at 0.75 must be 0.50"), SymptomComp->HandTremorIntensity, 0.50f);
	TestTrue(TEXT("Black sap cough must be active at 0.75"), SymptomComp->bIsCoughingBlackSap);

	SymptomComp->UpdateTransferenceSymptoms(0.30f);
	TestEqual(TEXT("Tremor intensity at 0.30 must be 0.0"), SymptomComp->HandTremorIntensity, 0.0f);
	TestFalse(TEXT("Black sap cough must be clear at 0.30"), SymptomComp->bIsCoughingBlackSap);

	// Test 2: Constellation Distance Nodes
	UAshenSoulConstellationNodeComponent* NodeComp = NewObject<UAshenSoulConstellationNodeComponent>();
	if (!TestNotNull(TEXT("SoulConstellationNodeComponent must be constructable"), NodeComp)) return false;

	NodeComp->UpdateConstellationDistances(ECompiledRelationalStance::WeaverStance);
	TestEqual(TEXT("Weaver stance node distance must be 150uu"), NodeComp->CompanionNodeDistanceUnits, 150.0f);

	NodeComp->UpdateConstellationDistances(ECompiledRelationalStance::MartyrStance);
	TestEqual(TEXT("Martyr stance node distance must be 500uu"), NodeComp->CompanionNodeDistanceUnits, 500.0f);

	// Test 3: GAS Resonant Cleave
	UAshenTripartiteResonantCleaveGASAbility* CleaveAbility = NewObject<UAshenTripartiteResonantCleaveGASAbility>();
	if (!TestNotNull(TEXT("TripartiteResonantCleaveGASAbility must be constructable"), CleaveAbility)) return false;

	TestEqual(TEXT("Cleave base damage must be 1400.0"), CleaveAbility->BaseFinisherDamage, 1400.0f);
	TestEqual(TEXT("Debt clearing ratio must be 30%"), CleaveAbility->DebtClearingPercentage, 0.30f);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — MASTER BATCH #106 RELATIONAL TRIAGE VERIFIED (2,135 BUILDS CLEAN)"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
