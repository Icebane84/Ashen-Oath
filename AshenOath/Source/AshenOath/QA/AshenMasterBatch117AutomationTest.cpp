// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "Companions/AshenSilenceClassifierComponent.h"
#include "Companions/AshenWordlessSupportEvaluatorComponent.h"
#include "Companions/AshenBoundaryRefusalEvaluatorComponent.h"
#include "Core/AshenSilenceSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch117AutomationTest,
	"AshenOath.Companions.MasterBatch117_SomaticSilence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch117AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST SOMATIC SILENCE CLASSIFIER (3 STATES)
	// -----------------------------------------------------------------------------------
	{
		UAshenSilenceClassifierComponent* Classifier = NewObject<UAshenSilenceClassifierComponent>();

		// Case A: Contemplative (Exploration, low dysregulation)
		const FSilenceEvaluationSnapshot Snap1 = Classifier->ClassifySilence(10.0f, 60.0f, 0.10f, false);
		TestEqual(TEXT("Classified as Contemplative"), Snap1.Classification, ESomaticSilenceClassification::Contemplative);
		TestNearlyEqual(TEXT("Recommended spacing is 500uu"), Snap1.RecommendedSpacingUU, 500.0f, 1.0f);

		// Case B: Traumatic Aftermath (Recent combat <= 15s, moderate dysregulation)
		const FSilenceEvaluationSnapshot Snap2 = Classifier->ClassifySilence(5.0f, 8.0f, 0.45f, false);
		TestEqual(TEXT("Classified as Traumatic Aftermath"), Snap2.Classification, ESomaticSilenceClassification::TraumaticAftermath);
		TestNearlyEqual(TEXT("Recommended spacing is 250uu"), Snap2.RecommendedSpacingUU, 250.0f, 1.0f);

		// Case C: Destabilizing Crisis (High dysregulation or memory trigger)
		const FSilenceEvaluationSnapshot Snap3 = Classifier->ClassifySilence(3.0f, 30.0f, 0.85f, true);
		TestEqual(TEXT("Classified as Destabilizing Crisis"), Snap3.Classification, ESomaticSilenceClassification::DestabilizingCrisis);
		TestNearlyEqual(TEXT("Recommended spacing is 200uu"), Snap3.RecommendedSpacingUU, 200.0f, 1.0f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST WORDLESS SUPPORT EVALUATOR (OBSTACLE CLEARANCE)
	// -----------------------------------------------------------------------------------
	{
		UAshenWordlessSupportEvaluatorComponent* WordlessEvaluator = NewObject<UAshenWordlessSupportEvaluatorComponent>();

		const FVector KaelenPos = FVector(0.0f, 0.0f, 0.0f);
		const FVector ObstaclePos = FVector(400.0f, 0.0f, 0.0f);

		// High trust Garrett clears obstacle proactively
		const FWordlessSupportCommand Cmd1 = WordlessEvaluator->EvaluateSupportAction(
			FName(TEXT("Garrett")), 0.75f, KaelenPos, ObstaclePos);
		TestEqual(TEXT("Garrett clears civilian obstacle"), Cmd1.ActionType, EWordlessSupportActionType::ClearCivilianObstacle);
		TestTrue(TEXT("Dialogue prompt is suppressed"), Cmd1.bSuppressDialoguePrompt);

		// Low trust does not proactively clear
		const FWordlessSupportCommand Cmd2 = WordlessEvaluator->EvaluateSupportAction(
			FName(TEXT("Garrett")), 0.40f, KaelenPos, ObstaclePos);
		TestEqual(TEXT("Low trust does not clear obstacle"), Cmd2.ActionType, EWordlessSupportActionType::None);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST COMPANION BOUNDARY REFUSAL ("NOBODY FOLLOWS")
	// -----------------------------------------------------------------------------------
	{
		UAshenBoundaryRefusalEvaluatorComponent* BoundaryEvaluator = NewObject<UAshenBoundaryRefusalEvaluatorComponent>();

		// Case A: Suicidal charge with high dysregulation -> High-trust companion REFUSES to follow
		const ECompanionBoundaryState State1 = BoundaryEvaluator->EvaluateBoundary(
			FName(TEXT("Garrett")), 0.80f, 0.85f, true);
		TestEqual(TEXT("High-trust companion executes Boundary Refusal"), State1, ECompanionBoundaryState::BoundaryRefusal);

		// Case B: Normal combat heroic charge -> Companion follows and supports
		const ECompanionBoundaryState State2 = BoundaryEvaluator->EvaluateBoundary(
			FName(TEXT("Garrett")), 0.80f, 0.20f, false);
		TestEqual(TEXT("Normal combat maintains Aligned Follow"), State2, ECompanionBoundaryState::AlignedFollow);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST SILENCE SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenSilenceSaveGameAdapter* SaveAdapter = NewObject<UAshenSilenceSaveGameAdapter>();

		SaveAdapter->PackageSilenceData(14, 3);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		int32 RestoredWordless = 0;
		int32 RestoredBoundary = 0;
		const bool bSuccess = SaveAdapter->RestoreSilenceData(RestoredWordless, RestoredBoundary);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Wordless count restored"), RestoredWordless, 14);
		TestEqual(TEXT("Boundary count restored"), RestoredBoundary, 3);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
