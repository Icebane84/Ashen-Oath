// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "Companions/AshenSerafinaBurnoutReceiverComponent.h"
#include "Companions/AshenStaggerResolutionEvaluatorComponent.h"
#include "Companions/AshenShadowOveruseAuditorComponent.h"
#include "Core/AshenTransferenceSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch116AutomationTest,
	"AshenOath.Companions.MasterBatch116_TransferenceBurnout",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch116AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST SERAFINA TRAUMA ABSORPTION & BURNOUT SEVERITY TIERS
	// -----------------------------------------------------------------------------------
	{
		UAshenSerafinaBurnoutReceiverComponent* BurnoutReceiver = NewObject<UAshenSerafinaBurnoutReceiverComponent>();

		// Initial state
		TestEqual(TEXT("Initial tier is Nominal"), BurnoutReceiver->GetBurnoutTier(), EBurnoutSeverityTier::Nominal);

		// Absorb 30 trauma -> Strained Tier
		const FTransferenceBurdenSnapshot Snap1 = BurnoutReceiver->AbsorbTraumaPayload(30.0f);
		TestEqual(TEXT("Tier shifted to Strained"), Snap1.BurnoutTier, EBurnoutSeverityTier::Strained);
		TestNearlyEqual(TEXT("Recovery delay penalty is 0.20s"), Snap1.RecoveryDelayPenaltySeconds, 0.20f, 0.01f);

		// Absorb 30 more trauma -> Exhausted Tier (Total 60)
		const FTransferenceBurdenSnapshot Snap2 = BurnoutReceiver->AbsorbTraumaPayload(30.0f);
		TestEqual(TEXT("Tier shifted to Exhausted"), Snap2.BurnoutTier, EBurnoutSeverityTier::Exhausted);
		TestNearlyEqual(TEXT("Recovery delay penalty is 0.40s"), Snap2.RecoveryDelayPenaltySeconds, 0.40f, 0.01f);

		// Reset at campfire
		BurnoutReceiver->ResetBurnoutAtCampfire();
		TestEqual(TEXT("Burnout reset to Nominal"), BurnoutReceiver->GetBurnoutTier(), EBurnoutSeverityTier::Nominal);
		TestNearlyEqual(TEXT("Cumulative burnout is 0"), BurnoutReceiver->GetCumulativeBurnout(), 0.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST MERCY VS EXECUTION EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenStaggerResolutionEvaluatorComponent* StaggerEvaluator = NewObject<UAshenStaggerResolutionEvaluatorComponent>();

		// Case A: Merciful Binding
		const FMercyExecutionEvaluationResult MercyResult = StaggerEvaluator->EvaluateChoice(
			EFoeStaggerResolutionChoice::MercifulBinding, true, 0.5f);
		TestTrue(TEXT("Serafina moral purity increases on mercy"), MercyResult.SerafinaMoralPurityDelta > 0.0f);
		TestTrue(TEXT("Dialogue reflects flame cleansing"), MercyResult.ContextualDialogue.Contains(TEXT("cleanses")));

		// Case B: Ruthless Execution on High Threat Elite
		const FMercyExecutionEvaluationResult ExecResult = StaggerEvaluator->EvaluateChoice(
			EFoeStaggerResolutionChoice::RuthlessExecution, false, 0.85f);
		TestTrue(TEXT("Garrett pragmatically approves high threat execution"), ExecResult.GarrettPragmaticApprovalDelta > 0.0f);
		TestTrue(TEXT("Serafina experiences moral grief"), ExecResult.SerafinaMoralPurityDelta < 0.0f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SHADOW MARK OVERUSE AUDITOR
	// -----------------------------------------------------------------------------------
	{
		UAshenShadowOveruseAuditorComponent* ShadowAuditor = NewObject<UAshenShadowOveruseAuditorComponent>();

		// Low usage
		EShadowMarkOveruseResponse Resp1 = ShadowAuditor->AuditShadowUsage(0.20f);
		TestEqual(TEXT("Disciplined usage permitted"), Resp1, EShadowMarkOveruseResponse::PermittedRestraint);

		// Moderate usage -> Verbal Caution
		EShadowMarkOveruseResponse Resp2 = ShadowAuditor->AuditShadowUsage(0.25f); // Total 0.45
		TestEqual(TEXT("Corruption triggers verbal caution"), Resp2, EShadowMarkOveruseResponse::VerbalCaution);

		// Excessive usage -> Physical Intervention
		EShadowMarkOveruseResponse Resp3 = ShadowAuditor->AuditShadowUsage(0.35f); // Total 0.80
		TestEqual(TEXT("Dangerous corruption triggers physical body-block"), Resp3, EShadowMarkOveruseResponse::PhysicalIntervention);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST TRANSFERENCE SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenTransferenceSaveGameAdapter* SaveAdapter = NewObject<UAshenTransferenceSaveGameAdapter>();

		SaveAdapter->PackageTransferenceData(45.5f, 7, 2);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		float RestoredBurnout = 0.0f;
		int32 RestoredMercy = 0;
		int32 RestoredExec = 0;
		const bool bSuccess = SaveAdapter->RestoreTransferenceData(RestoredBurnout, RestoredMercy, RestoredExec);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Burnout restored accurately"), RestoredBurnout, 45.5f, 0.01f);
		TestEqual(TEXT("Mercy count restored"), RestoredMercy, 7);
		TestEqual(TEXT("Execution count restored"), RestoredExec, 2);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
