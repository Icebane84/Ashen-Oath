// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Narrative/AshenForensicMindscapeTypes.h"
#include "Narrative/AshenForensicMindscapeConvergenceSubsystem.h"
#include "Narrative/AshenMemoryPalaceSynthesisEvaluator.h"
#include "Narrative/AshenForensicClueRegistryEvaluator.h"
#include "Narrative/AshenMindscapeSpectralDioramaComponent.h"
#include "Combat/AshenForensicMindscapeHapticBridge.h"
#include "Core/AshenForensicMindscapeSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch156AutomationTest,
	"AshenOath.Narrative.MasterBatch156_ForensicMindscapeConvergence",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch156AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST FORENSIC CLUE REGISTRY EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenForensicClueRegistryEvaluator* ClueEvaluator = NewObject<UAshenForensicClueRegistryEvaluator>();

		TestNearlyEqual(TEXT("Physical autopsy reliability is 1.0"), ClueEvaluator->GetCategoryReliabilityWeight(EForensicClueCategory::PhysicalAutopsyEvidence), 1.00f, 0.01f);
		TestNearlyEqual(TEXT("Chemical sample reliability is 0.95"), ClueEvaluator->GetCategoryReliabilityWeight(EForensicClueCategory::BotanicalChemicalSample), 0.95f, 0.01f);
		TestNearlyEqual(TEXT("Runic inscription reliability is 0.85"), ClueEvaluator->GetCategoryReliabilityWeight(EForensicClueCategory::HistoricalRunicInscription), 0.85f, 0.01f);
		TestNearlyEqual(TEXT("Companion testimony reliability is 0.65"), ClueEvaluator->GetCategoryReliabilityWeight(EForensicClueCategory::CompanionTestimony), 0.65f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST MEMORY PALACE SYNTHESIS EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenMemoryPalaceSynthesisEvaluator* SynthesisEvaluator = NewObject<UAshenMemoryPalaceSynthesisEvaluator>();

		// 3 clues with 1.0 reliability -> 1.0 score (Resolvable)
		const float HighScore = SynthesisEvaluator->EvaluateSynthesisScore(3, 1.0f);
		TestTrue(TEXT("Score is resolvable (>=0.85)"), SynthesisEvaluator->IsCaseResolvable(HighScore));

		// 1 clue with 0.65 reliability -> 0.22 score (Not resolvable)
		const float LowScore = SynthesisEvaluator->EvaluateSynthesisScore(1, 0.65f);
		TestFalse(TEXT("Low score is not resolvable (<0.85)"), SynthesisEvaluator->IsCaseResolvable(LowScore));

		// Contradiction detection
		TestTrue(TEXT("Physical vs Testimony triggers contradiction"), SynthesisEvaluator->DetectContradiction(EForensicClueCategory::PhysicalAutopsyEvidence, EForensicClueCategory::CompanionTestimony));
		TestFalse(TEXT("Physical vs Chemical does not trigger contradiction"), SynthesisEvaluator->DetectContradiction(EForensicClueCategory::PhysicalAutopsyEvidence, EForensicClueCategory::BotanicalChemicalSample));
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST SPECTRAL DIORAMA COMPONENT
	// -----------------------------------------------------------------------------------
	{
		UAshenMindscapeSpectralDioramaComponent* DioramaComp = NewObject<UAshenMindscapeSpectralDioramaComponent>();
		DioramaComp->ScrubTimeline(0.75f);

		TestNearlyEqual(TEXT("Timeline scrub position is 0.75"), DioramaComp->GetCurrentTimelinePosition(), 0.75f, 0.01f);
		TestTrue(TEXT("Reenactment is active"), DioramaComp->IsReenactmentActive());
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE FORENSIC HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenForensicMindscapeHapticBridge* HapticBridge = NewObject<UAshenForensicMindscapeHapticBridge>();
		float HeavyGain = 0.0f;
		float LightGain = 0.0f;

		// Reconstructed Truth Epiphany: 0.90 heavy, 0.95 light
		HapticBridge->EvaluateForensicHaptics(EMemoryReconstructionState::ReconstructedTruth, false, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Epiphany heavy motor gain is 0.90"), HeavyGain, 0.90f, 0.01f);
		TestNearlyEqual(TEXT("Epiphany light motor gain is 0.95"), LightGain, 0.95f, 0.01f);

		// Pinning Clue Snap: 0.35 heavy, 0.65 light
		HapticBridge->EvaluateForensicHaptics(EMemoryReconstructionState::DeductionInProgress, true, HeavyGain, LightGain);
		TestNearlyEqual(TEXT("Pin snap heavy gain is 0.35"), HeavyGain, 0.35f, 0.01f);
		TestNearlyEqual(TEXT("Pin snap light gain is 0.65"), LightGain, 0.65f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenForensicMindscapeSaveGameAdapter* SaveAdapter = NewObject<UAshenForensicMindscapeSaveGameAdapter>();
		SaveAdapter->PackageForensicState(12, 4, 0.92f);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		int32 RestoredDiscovered = 0;
		int32 RestoredSolved = 0;
		float RestoredSynthesis = 0.0f;

		const bool bSuccess = SaveAdapter->RestoreForensicState(RestoredDiscovered, RestoredSolved, RestoredSynthesis);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Restored discovered is 12"), RestoredDiscovered, 12);
		TestEqual(TEXT("Restored solved is 4"), RestoredSolved, 4);
		TestNearlyEqual(TEXT("Restored synthesis is 0.92"), RestoredSynthesis, 0.92f, 0.01f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
