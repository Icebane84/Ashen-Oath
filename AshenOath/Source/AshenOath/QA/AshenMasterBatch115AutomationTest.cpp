// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Companions/AshenCompanionIntentTypes.h"
#include "Companions/AshenGarrettIntentEvaluatorComponent.h"
#include "Companions/AshenSerafinaEmpathicIntentEvaluatorComponent.h"
#include "Companions/AshenHistoricalIntentProvenanceAuditor.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch115AutomationTest,
	"AshenOath.Companions.MasterBatch115_IntentInference",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch115AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST HIGH TRUST + INNOCENT RESCUE ("MR. HERO" SHOULDER-TO-SHOULDER COMMIT)
	// -----------------------------------------------------------------------------------
	{
		UAshenGarrettIntentEvaluatorComponent* GarrettEvaluator = NewObject<UAshenGarrettIntentEvaluatorComponent>();

		FPlayerIntentTelemetrySnapshot Telemetry;
		Telemetry.TelemetryId = TEXT("telemetry_rescue_001");
		Telemetry.bTargetIsInnocent = true;
		Telemetry.SoulState.DominantLens = EOntologicalLens::Grace;
		Telemetry.SoulState.AccumulatedDysregulation = 0.15f;

		const FCompanionIntentEvaluationResult Result = GarrettEvaluator->EvaluateGarrettIntent(Telemetry, EIntentConfidenceTier::Confident);

		TestEqual(TEXT("Intent is classified as InnocentRescue"), Result.InferredIntent, EPlayerFormationBreakIntent::InnocentRescue);
		TestEqual(TEXT("Garrett commits shoulder-to-shoulder"), Result.SelectedResponse, ECompanionTacticalResponse::ShoulderToShoulderCommit);
		TestTrue(TEXT("Contextual bark contains 'Mr. Hero'"), Result.ContextualBarkDialogue.Contains(TEXT("Mr. Hero")));
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST LOW TRUST + INNOCENT RESCUE (CAUTIOUS FLANK COMPENSATE)
	// -----------------------------------------------------------------------------------
	{
		UAshenGarrettIntentEvaluatorComponent* GarrettEvaluator = NewObject<UAshenGarrettIntentEvaluatorComponent>();

		FPlayerIntentTelemetrySnapshot Telemetry;
		Telemetry.TelemetryId = TEXT("telemetry_rescue_002");
		Telemetry.bTargetIsInnocent = true;
		Telemetry.SoulState.DominantLens = EOntologicalLens::Defiance;
		Telemetry.SoulState.AccumulatedDysregulation = 0.60f;

		const FCompanionIntentEvaluationResult Result = GarrettEvaluator->EvaluateGarrettIntent(Telemetry, EIntentConfidenceTier::Doubtful);

		TestEqual(TEXT("Intent is classified as InnocentRescue"), Result.InferredIntent, EPlayerFormationBreakIntent::InnocentRescue);
		TestEqual(TEXT("Garrett flanks cautiously to salvage position"), Result.SelectedResponse, ECompanionTacticalResponse::CautiousFlankCompensate);
		TestTrue(TEXT("Contextual bark vents frustration"), Result.ContextualBarkDialogue.Contains(TEXT("I said wait")));
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST HIGH TRUST + BLIND WRATH (CONFRONTATIONAL INTERVENTION)
	// -----------------------------------------------------------------------------------
	{
		UAshenGarrettIntentEvaluatorComponent* GarrettEvaluator = NewObject<UAshenGarrettIntentEvaluatorComponent>();

		FPlayerIntentTelemetrySnapshot Telemetry;
		Telemetry.TelemetryId = TEXT("telemetry_wrath_003");
		Telemetry.bTargetIsInnocent = false;
		Telemetry.SoulState.DominantLens = EOntologicalLens::Wrath;
		Telemetry.SoulState.AccumulatedDysregulation = 0.85f;

		const FCompanionIntentEvaluationResult Result = GarrettEvaluator->EvaluateGarrettIntent(Telemetry, EIntentConfidenceTier::Confident);

		TestEqual(TEXT("Intent is classified as BlindWrathAssault"), Result.InferredIntent, EPlayerFormationBreakIntent::BlindWrathAssault);
		TestEqual(TEXT("Garrett physically intervenes to stop Kaelen"), Result.SelectedResponse, ECompanionTacticalResponse::ConfrontationalIntervene);
		TestTrue(TEXT("Contextual bark confronts Kaelen's rage"), Result.ContextualBarkDialogue.Contains(TEXT("Not this time")));
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST INTENT CONFIDENCE AUDITOR
	// -----------------------------------------------------------------------------------
	{
		UAshenHistoricalIntentProvenanceAuditor* Auditor = NewObject<UAshenHistoricalIntentProvenanceAuditor>();

		FCanonicalSoulStateVector StableGraceState;
		StableGraceState.DominantLens = EOntologicalLens::Grace;
		StableGraceState.AccumulatedDysregulation = 0.15f;

		const EIntentConfidenceTier HighTier = Auditor->AuditIntentConfidence(true, StableGraceState);
		TestEqual(TEXT("Stable Grace with innocent target achieves Absolute/Confident tier"), HighTier, EIntentConfidenceTier::Absolute);

		FCanonicalSoulStateVector HighDysregState;
		HighDysregState.AccumulatedDysregulation = 0.80f;

		const EIntentConfidenceTier LowTier = Auditor->AuditIntentConfidence(false, HighDysregState);
		TestEqual(TEXT("High Dysregulation drops confidence to Doubtful"), LowTier, EIntentConfidenceTier::Doubtful);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SERAFINA INTENT EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenSerafinaEmpathicIntentEvaluatorComponent* SerafinaEvaluator = NewObject<UAshenSerafinaEmpathicIntentEvaluatorComponent>();

		FPlayerIntentTelemetrySnapshot Telemetry;
		Telemetry.bTargetIsInnocent = true;

		const FCompanionIntentEvaluationResult Result = SerafinaEvaluator->EvaluateSerafinaIntent(Telemetry, EIntentConfidenceTier::Confident);
		TestEqual(TEXT("Serafina responds with DefensiveSanctuaryHold"), Result.SelectedResponse, ECompanionTacticalResponse::DefensiveSanctuaryHold);
		TestTrue(TEXT("Serafina bark offers flame shelter"), Result.ContextualBarkDialogue.Contains(TEXT("shelter")));
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
